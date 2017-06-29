/*
 *
 *  ZDKRMADialogViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/02/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import "ZDKRMAFeedbackView.h"
#import "ZDKRMADialogView.h"
#import "ZDKUIViewController.h"


@class ZDKRMA;


__deprecated_msg("Deprecated as of 1.10.0.1, this will be removed.")

/**
 * The ZDKRMADialogViewController manages the two views that make up ZDKRMA.
 */
@interface ZDKRMADialogViewController : ZDKUIViewController <ZDKRMADialogViewDelegate, ZDKRMAFeedbackViewDelegate>


/**
 * A ZDKRMADialogView to be presented.
 */
@property (nonatomic, strong) ZDKRMADialogView *dialog;


/**
 * A ZDKRMAFeedbackView to be presented.
 */
@property (nonatomic, strong) ZDKRMAFeedbackView *feedbackView;


/**
 * Initializes and returns a ZDKRMADialogViewController.
 *
 * This creates a ZDKRMADialogViewController.
 *
 * @param config The instance of ZDKRMA. 
 * @return An initialized ZDKRMADialogViewController.
 *
 */
- (instancetype) initWithConfig:(ZDKRMAConfigObject*)config;

@end
