//
//  ZDSampleAppConfigurationViewController.h
//  SampleApp
//
//  Created by Zendesk on 11/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ZendeskSDK/ZendeskSDK.h>
#import "ZDSampleAppScanViewController.h"

@protocol ZDAppConfigurationDelegate <NSObject>

- (void) configuration:(NSString *) url withAppId:(NSString *) appId andClientId:(NSString *) clientId;

@end

@interface ZDSampleAppConfigurationViewController : ZDKUIViewController <UITextFieldDelegate, ZDSampleAppScanViewControllerDelegate>

@property (nonatomic, strong) id <ZDAppConfigurationDelegate> delegate;

@end
