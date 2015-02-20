//
//  ZDSampleViewController.h
//  SampleApp
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <ZendeskSDK/ZendeskSDK.h>
#import "ZDSampleAppConfigurationViewController.h"


@interface ZDSampleViewController : ZDKUIViewController <ZDAppCondigurationDelegate>


@property (nonatomic, strong) UIButton *requestCreationButton;
@property (nonatomic, strong) UIButton *requestListButton;
@property (nonatomic, strong) UITextField *helpCenterLabelsInput;
@property (nonatomic, strong) UIButton *helpCenterButton;
@property (nonatomic, strong) UIButton *rmaButton;
@property (nonatomic, strong) UINavigationController *modalNavController;


@end

