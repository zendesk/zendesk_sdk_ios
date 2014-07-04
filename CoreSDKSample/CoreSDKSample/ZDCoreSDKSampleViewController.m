//
//  ZDCoreSDKSampleViewController.m
//  CoreSDK
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDCoreSDKSampleViewController.h"


@implementation ZDCoreSDKSampleViewController


- (void) viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Core SDK Sample";

    _requestCreationButton = [self buildButtonWithFrame:CGRectZero andTitle:@"Present CoreSDK Request Creation"];
    _requestCreationButton.accessibilityIdentifier = @"zdrma.sampleapp.push-view-button";
    _requestCreationButton.backgroundColor = [UIColor whiteColor];
    [_requestCreationButton addTarget:self action:@selector(createRequest) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_requestCreationButton];

    // request list header
    _header = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 25)];
    _header.backgroundColor = [UIColor colorWithWhite:0.97f alpha:1.0f];
    [self.view addSubview:_header];

    float borderHeight = [UIScreen mainScreen].scale == 1.0 ? 1 : 0.5;

    UIView *topBorder = [[UIView alloc] initWithFrame:CGRectMake(0, 0, _header.frame.size.width, borderHeight)];
    topBorder.backgroundColor = [UIColor colorWithWhite:0.88f alpha:1.0f];
    topBorder.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [_header addSubview:topBorder];

    UILabel *headerLabel = [[UILabel alloc] initWithFrame:CGRectMake(25.0f, 0, _header.frame.size.width, _header.frame.size.height)];
    headerLabel.backgroundColor = [UIColor clearColor];
    headerLabel.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    headerLabel.text = @"YOUR REQUESTS";
    headerLabel.textColor = [UIColor colorWithWhite:0.33f alpha:1.0f];
    headerLabel.font = [UIFont systemFontOfSize:11];
    [_header addSubview:headerLabel];

    UIView *lowerBorder = [[UIView alloc] initWithFrame:CGRectMake(0, _header.frame.size.height - borderHeight, _header.frame.size.width, borderHeight)];
    lowerBorder.backgroundColor = [UIColor colorWithWhite:0.88f alpha:1.0f];
    lowerBorder.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [_header addSubview:lowerBorder];


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Create the request list and add it to your UI and register for events
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // set the user details
    [ZDCoreSDK configure:^(ZDAccount *account, ZDRequestCreationConfig *requestCreationConfig) {

        account.userToken = @"a_token";
        account.clientId = @"a_client_id";
        account.email = @"example@example.com";
    }];

    
    
    // wrap the request list view into a scrollview.
    _requestList = [ZDCoreSDK newRequestListWith:self andSelector:@selector(requestListUpdated)];
    _requestListContainer = [[UIScrollView alloc] initWithFrame:CGRectZero];
    [self.requestListContainer addSubview:_requestList];
    
    [self.view addSubview:_requestListContainer];
}


- (void) viewWillLayoutSubviews
{
    [super viewWillLayoutSubviews];

    _requestCreationButton.frame = CGRectMake(20.0f, [self topViewOffset] + 20.0f,
                                              self.view.frame.size.width - 40.0f, 30.0f);

    _header.frame = CGRectMake(0, [self topViewOffset] + 70.0f, self.view.frame.size.width, _header.frame.size.height);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // On layout setup the request list frame as desired, using 'tableHeight' to get the table height
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    float containerOriginY = CGRectGetMaxY(_header.frame);
    float containerHeight = self.view.frame.size.height - containerOriginY;
    
    _requestListContainer.frame = CGRectMake(0, containerOriginY , self.view.frame.size.width, containerHeight);
    _requestListContainer.contentSize = CGSizeMake(self.view.frame.size.width, [_requestList tableHeight]);
    
    _requestList.frame= CGRectMake(0, 0, self.view.frame.size.width, [_requestList tableHeight]);
}


- (void) requestListUpdated
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // On receiving a notification the table has been updated, use the new height to arrange your UI
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [UIView animateWithDuration:0.25f animations:^{
        _requestList.frame= CGRectMake(0, CGRectGetMaxY(_header.frame), self.view.frame.size.width, [_requestList tableHeight]);
    }];
    
    [self.view setNeedsLayout];
}


- (void) dealloc
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Remember to remove this class as a notification observer on dealloc
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [_requestList unregisterForEvents:self];
}


#pragma mark request creation


- (void) createRequest
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Show the request creation screen
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [ZDCoreSDK showRequestCreationWithNavController:self.navigationController
                                      withSuccess:^(NSData *data) {

        //  refresh the request list
        [_requestList refresh];

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


@end

