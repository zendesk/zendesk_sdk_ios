//
//  ZDCoreSDKSampleViewController.m
//  CoreSDK
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDCoreSDKSampleViewController.h"
#import "ZDRateMyAppDemoViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation ZDCoreSDKSampleViewController


- (void) viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"SDK Sample App";
    
    _rmaButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Show Rate My App"];
    _rmaButton.accessibilityIdentifier = @"zdrma.sampleapp.requests-in-scrollview-button";
    _rmaButton.backgroundColor = [UIColor whiteColor];
    [_rmaButton addTarget:self action:@selector(rateMyApp) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_rmaButton];

    _requestCreationButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Contact Zendesk"];
    _requestCreationButton.accessibilityIdentifier = @"zdrma.sampleapp.push-view-button";
    _requestCreationButton.backgroundColor = [UIColor whiteColor];
    [_requestCreationButton addTarget:self action:@selector(createRequest) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_requestCreationButton];

    _requestListButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Ticket List"];
    _requestListButton.accessibilityIdentifier = @"zdrma.sampleapp.requests-in-scrollview-button";
    _requestListButton.backgroundColor = [UIColor whiteColor];
    [_requestListButton addTarget:self action:@selector(requestListView) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_requestListButton];


    _helpCenterLabelsInput = [self buildTextFieldWithFrame:CGRectZero andPlaceholder:@"label1,label2,label3 (optional)"];
    _helpCenterLabelsInput.accessibilityIdentifier = @"zdrma.sampleapp.labels-text-input-field";
    _helpCenterLabelsInput.backgroundColor = [UIColor whiteColor];
    //helpCenterButton pulls these out
    [self.contentView addSubview:_helpCenterLabelsInput];
    
    
    _helpCenterButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Support"];
    _helpCenterButton.accessibilityIdentifier = @"zdrma.sampleapp.requests-in-scrollview-button";
    _helpCenterButton.backgroundColor = [UIColor whiteColor];
    [_helpCenterButton addTarget:self action:@selector(support) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_helpCenterButton];
    


    
    ZDCoreSDKSampleAppConfigurationViewController *configurationVC = [[ZDCoreSDKSampleAppConfigurationViewController alloc] initWithNibName:nil bundle:nil];
    configurationVC.delegate = self;
    
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:configurationVC];


    [self.parentViewController presentViewController:navController animated:NO completion:^{}];
}


- (void) requestListView
{
    [ZDKRequests showRequestListWithNavController:self.navigationController];
}


- (void) support
{
    if(_helpCenterLabelsInput.hasText){
        NSString *labelString = _helpCenterLabelsInput.text;
        NSArray *labels = [labelString componentsSeparatedByString:@","];
        [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController filterByArticleLabels:labels];
    }else{
        [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController];
    }
}


- (void) rateMyApp
{
    ZDRateMyAppDemoViewController *vc = [[ZDRateMyAppDemoViewController alloc] initWithNibName:nil bundle:nil];
    [self.navigationController pushViewController:vc animated:YES];
}


- (void) viewWillLayoutSubviews
{
    [super viewWillLayoutSubviews];

    CGFloat width = self.contentView.frame.size.width - 40.0f;
    
    
    _rmaButton.frame = CGRectMake(20.0f, 20.0f, width, 30.0f);
    
    _requestCreationButton.frame = CGRectMake(20.0f, 60.0f, width, 30.0f);

    _requestListButton.frame = CGRectMake(20.0f, 100.0f, width, 30.0f);
    
    _helpCenterLabelsInput.frame = CGRectMake(20.0f, 140.0f, width, 30.0f);
    
    _helpCenterButton.frame = CGRectMake(20.0f, 180.0f, width, 30.0f);
    
   

}


#pragma mark request creation


- (void) createRequest
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Show the request creation screen
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [ZDKRequests showRequestCreationWithNavController:self.navigationController
                                      withSuccess:^(NSData *data) {

        // do something here if you want to...

    } andError:^(NSError *err) {

        // do something here if you want to...
    }];
}



#pragma mark - control creation


- (UIControl *) buildControl:(UIControl *) control
{
    control.layer.borderColor = [UIColor colorWithWhite:0.8470f alpha:1.0f].CGColor;
    control.layer.borderWidth = 1.0f;
    control.layer.cornerRadius = 4.0f;
    control.autoresizingMask = UIViewAutoresizingFlexibleBottomMargin |
                                UIViewAutoresizingFlexibleTopMargin |
                                UIViewAutoresizingFlexibleLeftMargin |
                                UIViewAutoresizingFlexibleRightMargin;
    return control;
}


- (UITextField *) buildTextFieldWithFrame:(CGRect)frame andPlaceholder:(NSString *)placeholder
{
    UITextField * textField = [[UITextField alloc] initWithFrame:frame];
    textField = (UITextField *)[self buildControl:textField];
    
    [textField setPlaceholder:placeholder];
    textField.textAlignment = NSTextAlignmentCenter;
    
    
    return textField;
}



- (UIButton *) buildButtonWithFrame:(CGRect)frame andTitle:(NSString*)title
{
    UIButton *button = [[UIButton alloc] initWithFrame:frame];
    button = (UIButton *)[self buildControl:button];
    
    button.titleLabel.font = [UIFont systemFontOfSize:14];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:1.0f] forState:UIControlStateNormal];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateHighlighted];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateDisabled];
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitle:title forState:UIControlStateHighlighted];
    button.titleLabel.textAlignment = NSTextAlignmentCenter;
    
    return button;
}


- (void) configuration:(NSString *) url withAppId:(NSString *) appId withClientId:(NSString *) clientId withUserId:(NSString *) userId
{
    NSLog(@"configuration made, url: %@, appId: %@, clientId: %@ and userToken: %@",url,appId,clientId, userId);

    [[ZDKConfig instance] initializeWithAppId:appId zendeskUrl:url oAuthClientId:clientId andUserId:userId];
    
}

@end
