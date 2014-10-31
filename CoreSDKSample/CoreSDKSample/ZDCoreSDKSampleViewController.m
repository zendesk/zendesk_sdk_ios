//
//  ZDCoreSDKSampleViewController.m
//  CoreSDK
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDCoreSDKSampleViewController.h"
#import "RequestListViewController.h"
#import "RequestListTableViewController.h"
#import "ZDRateMyAppDemoViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation ZDCoreSDKSampleViewController


- (void) viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"SDK Sample App";

    _requestCreationButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Present CoreSDK Request Creation"];
    _requestCreationButton.accessibilityIdentifier = @"zdrma.sampleapp.push-view-button";
    _requestCreationButton.backgroundColor = [UIColor whiteColor];
    [_requestCreationButton addTarget:self action:@selector(createRequest) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_requestCreationButton];

    _requestListInScrollViewButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Request List in UIScrollView"];
    _requestListInScrollViewButton.accessibilityIdentifier = @"zdrma.sampleapp.requests-in-scrollview-button";
    _requestListInScrollViewButton.backgroundColor = [UIColor whiteColor];
    [_requestListInScrollViewButton addTarget:self action:@selector(requestListInScrollView) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_requestListInScrollViewButton];

    _requestListInTableButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Request List in UITableView"];
    _requestListInTableButton.accessibilityIdentifier = @"zdrma.sampleapp.requests-in-scrollview-button";
    _requestListInTableButton.backgroundColor = [UIColor whiteColor];
    [_requestListInTableButton addTarget:self action:@selector(requestListInTable) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_requestListInTableButton];
    
    
    _helpCenterButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Show Help Center"];
    _helpCenterButton.accessibilityIdentifier = @"zdrma.sampleapp.requests-in-scrollview-button";
    _helpCenterButton.backgroundColor = [UIColor whiteColor];
    [_helpCenterButton addTarget:self action:@selector(support) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_helpCenterButton];

    _rmaButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Show Rate My App"];
    _rmaButton.accessibilityIdentifier = @"zdrma.sampleapp.requests-in-scrollview-button";
    _rmaButton.backgroundColor = [UIColor whiteColor];
    [_rmaButton addTarget:self action:@selector(rateMyApp) forControlEvents:UIControlEventTouchUpInside];
    [self.contentView addSubview:_rmaButton];
    
    ZDCoreSDKSampleAppConfigurationViewController *configurationVC = [[ZDCoreSDKSampleAppConfigurationViewController alloc] initWithNibName:nil bundle:nil];
    configurationVC.delegate = self;
    
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:configurationVC];


    [self.parentViewController presentViewController:navController animated:NO completion:^{}];
}

- (void) requestListInScrollView
{
    RequestListViewController *vc = [RequestListViewController new];
    vc.title = self.title;
    [self.navigationController pushViewController:vc animated:YES];
}


- (void) requestListInTable
{
    RequestListTableViewController *vc = [RequestListTableViewController new];
    vc.title = self.title;
    [self.navigationController pushViewController:vc animated:YES];
}


- (void) support
{
    [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController];
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
    
    _requestCreationButton.frame = CGRectMake(20.0f, 20.0f, width, 30.0f);

    _requestListInScrollViewButton.frame = CGRectMake(20.0f, 60.0f, width, 30.0f);

    _requestListInTableButton.frame = CGRectMake(20.0f, 100.0f, width, 30.0f);
    
    _helpCenterButton.frame = CGRectMake(20.0f, 140.0f, width, 30.0f);
    
    _rmaButton.frame = CGRectMake(20.0f, 180.0f, width, 30.0f);

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


#pragma mark - button creation 


- (UIButton*) buildButtonWithFrame:(CGRect)frame andTitle:(NSString*)title
{
    UIButton *button = [[UIButton alloc] initWithFrame:frame];
    button.backgroundColor = [UIColor colorWithWhite:0.9450f alpha:1.0f];
    button.layer.borderColor = [UIColor colorWithWhite:0.8470f alpha:1.0f].CGColor;
    button.layer.borderWidth = 1.0f;
    button.layer.cornerRadius = 4.0f;
    button.titleLabel.font = [UIFont systemFontOfSize:14];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:1.0f] forState:UIControlStateNormal];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateHighlighted];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateDisabled];
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitle:title forState:UIControlStateHighlighted];
    button.titleLabel.textAlignment = NSTextAlignmentCenter;
    button.autoresizingMask = UIViewAutoresizingFlexibleBottomMargin |
                                UIViewAutoresizingFlexibleTopMargin |
                                UIViewAutoresizingFlexibleLeftMargin |
                                UIViewAutoresizingFlexibleRightMargin;
    return button;
}

- (void) configuration:(NSString *) url withAppId:(NSString *) appId withClientId:(NSString *) clientId withUserId:(NSString *) userId {
    NSLog(@"configuration made, url: %@, appId: %@, clientId: %@ and userToken: %@",url,appId,clientId, userId);

    [[ZDKConfig instance] initializeWithAppId:appId zendeskUrl:url oAuthClientId:clientId andUserId:userId];
    
}

@end

