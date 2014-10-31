//
//  ZDCoreSDKSampleViewController.h
//  CoreSDK
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <ZendeskSDK/ZendeskSDK.h>
#import "ZDCoreSDKSampleAppConfigurationViewController.h"


@interface ZDCoreSDKSampleViewController : ZDKUIViewController <ZDCoreSDKAppCondigurationDelegate>


@property (nonatomic, strong) UIButton *requestCreationButton;
@property (nonatomic, strong) UIButton *requestListInScrollViewButton;
@property (nonatomic, strong) UIButton *requestListInTableButton;
@property (nonatomic, strong) UIButton *helpCenterButton;
@property (nonatomic, strong) UIButton *rmaButton;



@end

