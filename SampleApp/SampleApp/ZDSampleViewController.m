//
//  ZDSampleViewController.m
//  SampleApp
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDSampleViewController.h"
#import "ZDRateMyAppDemoViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation ZDSampleViewController


@synthesize rmaButton, requestCreationButton, requestListButton, helpCenterButton, helpCenterLabelsInput;
@synthesize registerPush, unregisterPush;

- (void) viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"SDK Sample";
    
    rmaButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Show Rate My App"];
    rmaButton.accessibilityIdentifier = @"rmaButton";
    rmaButton.backgroundColor = [UIColor whiteColor];
    [rmaButton addTarget:self action:@selector(rateMyApp) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:rmaButton];

    requestCreationButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Contact Zendesk"];
    requestCreationButton.accessibilityIdentifier = @"contactZendeskButton";
    requestCreationButton.backgroundColor = [UIColor whiteColor];
    [requestCreationButton addTarget:self action:@selector(createRequest) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:requestCreationButton];

    requestListButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Ticket List"];
    requestListButton.accessibilityIdentifier = @"ticketListButton";
    requestListButton.backgroundColor = [UIColor whiteColor];
    [requestListButton addTarget:self action:@selector(requestListView) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:requestListButton];


    helpCenterLabelsInput = [ZDSampleViewController buildTextFieldWithFrame:CGRectZero andPlaceholder:@"label1,label2,label3 (optional)"];
    helpCenterLabelsInput.accessibilityIdentifier = @"hcLabelsField";
    helpCenterLabelsInput.backgroundColor = [UIColor whiteColor];
    //helpCenterButton pulls these out
    [self.contentView addSubview:helpCenterLabelsInput];
    
    
    helpCenterButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Support"];
    helpCenterButton.accessibilityIdentifier = @"supportButton";
    helpCenterButton.backgroundColor = [UIColor whiteColor];
    [helpCenterButton addTarget:self action:@selector(support) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:helpCenterButton];
    

    registerPush = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Register Push"];
    registerPush.accessibilityIdentifier = @"registerButton";
    registerPush.backgroundColor = [UIColor whiteColor];
    [registerPush addTarget:self action:@selector(registerForPush) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:registerPush];
    
    unregisterPush = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Unregister Push"];
    unregisterPush.accessibilityIdentifier = @"unregisterButton";
    unregisterPush.backgroundColor = [UIColor whiteColor];
    [unregisterPush addTarget:self action:@selector(unregisterForPush) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:unregisterPush];
    
    [self setupConstraints];

    ZDSampleAppConfigurationViewController *configurationVC = [[ZDSampleAppConfigurationViewController alloc] initWithNibName:nil bundle:nil];
    configurationVC.delegate = self;

    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:configurationVC];

    [self.parentViewController presentViewController:navController animated:NO completion:^{}];

}


- (void) setupConstraints
{
    NSDictionary *metrics = @{@"padding":@(20), @"height":@(30)};

    NSDictionary *views = NSDictionaryOfVariableBindings(rmaButton,
                                                         requestCreationButton,
                                                         requestListButton,
                                                         helpCenterLabelsInput,
                                                         helpCenterButton,
                                                         registerPush,
                                                         unregisterPush);

    [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-padding-[rmaButton]-padding-|"
                                                                             options:NSLayoutFormatAlignmentMask
                                                                             metrics:metrics
                                                                               views:views]];

    [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-[rmaButton(height)]-padding-[requestCreationButton(height)]-padding-[requestListButton(height)]-padding-[helpCenterLabelsInput(height)]-padding-[helpCenterButton(height)]-padding-[registerPush(height)]-padding-[unregisterPush(height)]"
                                                                             options:NSLayoutFormatAlignAllLeft | NSLayoutFormatAlignAllRight
                                                                             metrics:metrics
                                                                               views:views]];
}


#pragma mark - SDK


- (void) requestListView
{
    if([ZDKUIUtil isPad]) {

        self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
        [ZDKRequests presentRequestListWithNavController:self.navigationController];

    } else {
        
        [ZDKRequests showRequestListWithNavController:self.navigationController];
    }
}


- (void) support
{
    
    if (helpCenterLabelsInput.hasText) {

        NSString *labelString = helpCenterLabelsInput.text;
        NSArray *labels = [labelString componentsSeparatedByString:@","];


        if([ZDKUIUtil isPad]) {

            self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
            [ZDKHelpCenter presentHelpCenterWithNavController:self.navigationController filterByArticleLabels:labels];

        } else {

            [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController filterByArticleLabels:labels];
        }

    } else {

        if([ZDKUIUtil isPad]) {

            self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
            [ZDKHelpCenter presentHelpCenterWithNavController:self.navigationController];

        } else {

            [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController];
        }
    }
}

- (void) rateMyApp
{
    ZDRateMyAppDemoViewController *vc = [[ZDRateMyAppDemoViewController alloc] initWithNibName:nil bundle:nil];
    [self.navigationController pushViewController:vc animated:YES];
}


#pragma mark request creation


- (void) createRequest
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Show the request creation screen
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if([ZDKUIUtil isPad]) {
        
        self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
    }

    [ZDKRequests showRequestCreationWithNavController:self.navigationController];
}

#pragma mark Push notifications

- (void) registerForPush
{
    
    NSString *identifier = [self getDeviceId];
    
    [[ZDKConfig instance] enablePush:identifier callback:^(ZDKPushRegistrationResponse *registrationResponse, NSError *error) {
        
        NSString *title;

        if (error) {
            
            title = @"Registration Failed";
            [ZDKLogger log:@"Couldn't register device: %@. Error: %@", identifier, error];
            
        } else if (registrationResponse) {
            
            title = @"Registration Successful";
            [ZDKLogger log:@"Successfully registered device: %@", identifier];
        }

        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:title message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
        [alert show];
    }];
}

- (void) unregisterForPush
{
    NSString *identifier = [self getDeviceId];
    
    [[ZDKConfig instance] disablePush:identifier callback:^(NSNumber *responseCode, NSError *error) {

        NSString *title;

        if (error) {
            
            title = @"Failed to Unregister";
            [ZDKLogger log:@"Couldn't unregister device: %@. Error: %@", identifier, error];
            
        } else if (responseCode) {
            
            title = @"Unregistered";
            [ZDKLogger log:@"Successfully unregistered device: %@", identifier];
        }

        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:title message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
        [alert show];
    }];
    
}

- (NSString*) getDeviceId
{
    NSString *result = [[NSUserDefaults standardUserDefaults] objectForKey:APPLE_PUSH_UUID];
    
    return result;
}

#pragma mark - control creation


+ (UIControl *) buildControl:(UIControl *) control
{
    control.layer.borderColor = [UIColor colorWithWhite:0.8470f alpha:1.0f].CGColor;
    control.translatesAutoresizingMaskIntoConstraints = NO;
    control.layer.borderWidth = 1.0f;
    control.layer.cornerRadius = 4.0f;
    return control;
}


+ (UITextField *) buildTextFieldWithFrame:(CGRect)frame andPlaceholder:(NSString *)placeholder
{
    UITextField * textField = [[UITextField alloc] initWithFrame:frame];
    textField = (UITextField *)[self buildControl:textField];
    textField.textAlignment = NSTextAlignmentCenter;
    textField.placeholder = placeholder;

    return textField;
}


+ (UIButton *) buildButtonWithFrame:(CGRect)frame andTitle:(NSString*)title
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


- (void)configuration:(NSString *)url withAppId:(NSString *)appId andClientId:(NSString *)clientId
{
    NSLog(@"configuration made, url: %@, appId: %@ and clientId: %@",url,appId,clientId);
    [[ZDKConfig instance] initializeWithAppId:appId zendeskUrl:url andClientId:clientId];
}


@end
