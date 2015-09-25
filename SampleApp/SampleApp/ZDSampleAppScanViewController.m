/*
 *  Portions of the software Copyright (c) 2013 Alexander Mack, ama-dev.com
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 *  documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 *  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or substantial
 *  portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  Remaining portions of the software Copyright (c) 2015 Zendesk, Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 *  ZDSampleAppScanViewController.m
 *  SampleApp
 *
 *  Created by Zendesk on 3/6/15.
 *  Based off the work of Alexander Mack on 11.10.13. MIT Licence.
 *  Copyright (c) 2013 ama-dev.com. All rights reserved
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 * By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 * of Service ( https://www.zendesk.com/company/terms ) and Application Developer and API License
 * Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 * acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import "ZDSampleAppScanViewController.h"

/**
 *  Small class just to draw a rectangle on the view to provide some indication on where
 *  the qr code should be. The size of saif rect is "empirically derived".
 */
@interface TargetingView : UIView

@end

@implementation TargetingView



- (void)drawRect:(CGRect)rect
{
    CGFloat size = 250.0f;
    CGFloat width = self.frame.size.width;
    CGFloat height = self.frame.size.height;
    UIBezierPath *p= [UIBezierPath bezierPathWithRect:CGRectMake((width / 2) - (size / 2),
                                                                 (height / 2) - (size / 2) ,
                                                                 size,
                                                                 size)];
    [[UIColor blackColor] setStroke];
    p.lineWidth = 4.0f;
    [p stroke];
}

@end


@interface ZDSampleAppScanViewController ()

@property (strong, nonatomic) AVCaptureDevice* captureDevice;
@property (strong, nonatomic) AVCaptureDeviceInput* captureInput;
@property (strong, nonatomic) AVCaptureMetadataOutput* captureOutput;
@property (strong, nonatomic) AVCaptureSession* captureSession;
@property (strong, nonatomic) AVCaptureVideoPreviewLayer* cameraStream;

@end

@implementation ZDSampleAppScanViewController


#pragma mark - UIViewController methods

- (void)viewWillAppear:(BOOL)animated;
{
    [super viewWillAppear:animated];
    
    if([self isCameraAvailable]) {
        [self startScanning];
    } else {
        [self setupNoCameraView];
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    if([self isCameraAvailable]) {
        [self setupScanner];
        TargetingView *target = [[TargetingView alloc] initWithFrame:self.view.frame];
        target.backgroundColor = [UIColor clearColor];
        
        [self.view addSubview:target];
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self stopScanning];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations;
{
    return UIInterfaceOrientationMaskPortrait;
}

- (BOOL)shouldAutorotate;
{
    return NO;
}


#pragma mark - No Camera

- (void) setupNoCameraView;
{
    self.view.backgroundColor = [UIColor lightGrayColor];
    UILabel *noCamLabel = [[UILabel alloc] init];
    noCamLabel.text = @"No camera available";
    noCamLabel.textColor = [UIColor blackColor];
    //noCamLabel
    [self.view addSubview:noCamLabel];
    
    [noCamLabel sizeToFit];
    noCamLabel.center = self.view.center;
}


#pragma mark - Setup camera scanner

- (void) setupScanner;
{
    self.captureDevice = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    self.captureSession = [[AVCaptureSession alloc] init];
    self.captureOutput = [[AVCaptureMetadataOutput alloc] init];
    self.captureInput = [AVCaptureDeviceInput deviceInputWithDevice:self.captureDevice error:nil];
    
    [self.captureSession addOutput:self.captureOutput];
    [self.captureSession addInput:self.captureInput];
    
    [self.captureOutput setMetadataObjectsDelegate:self queue:dispatch_get_main_queue()];
    self.captureOutput.metadataObjectTypes = @[AVMetadataObjectTypeQRCode];
    
    self.cameraStream = [AVCaptureVideoPreviewLayer layerWithSession:self.captureSession];
    self.cameraStream.videoGravity = AVLayerVideoGravityResizeAspectFill;
    self.cameraStream.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    
    AVCaptureConnection *connection = self.cameraStream.connection;
    connection.videoOrientation = AVCaptureVideoOrientationPortrait;
    
    
    [self.view.layer insertSublayer:self.cameraStream atIndex:0];
}

#pragma mark - Helper Methods

- (BOOL) isCameraAvailable;
{
    NSArray *captureDevices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    return [captureDevices count] > 0;
}

- (void)startScanning;
{
    [self.captureSession startRunning];
}

- (void) stopScanning;
{
    [self.captureSession stopRunning];
}

#pragma mark - AVCaptureMetadataOutputObjectsDelegate

- (void)captureOutput:(AVCaptureOutput *)captureOutput didOutputMetadataObjects:(NSArray *)metadataObjects
       fromConnection:(AVCaptureConnection *)connection
{
    for(AVMetadataObject *metaData in metadataObjects) {
        if([metaData isKindOfClass:[AVMetadataMachineReadableCodeObject class]]) {
            
            if([self.delegate respondsToSelector:@selector(didScan:)]) {
                NSString *result = [((AVMetadataMachineReadableCodeObject *) metaData) stringValue];
                [self stopScanning];
                [self.delegate didScan:result];
                [self dismissViewControllerAnimated:YES completion:nil];
            }
            
        }
        
    }
}


@end


