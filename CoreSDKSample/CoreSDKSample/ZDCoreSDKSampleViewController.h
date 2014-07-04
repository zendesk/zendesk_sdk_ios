//
//  ZDCoreSDKSampleViewController.h
//  CoreSDK
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <ZendeskSDK/ZDCoreSDK.h>


@interface ZDCoreSDKSampleViewController : ZDUIUIViewController


@property (nonatomic, strong) UIButton *requestCreationButton;
@property (nonatomic, strong) ZDRequestListTable *requestList;
@property (nonatomic, strong) UIScrollView *requestListContainer;

@property (nonatomic, strong) UIView *header;


@end

