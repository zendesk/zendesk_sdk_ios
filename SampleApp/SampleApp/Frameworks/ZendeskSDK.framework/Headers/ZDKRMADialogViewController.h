/*
 *
 *  ZDKRMADialogViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/02/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import "ZDKRMAFeedbackView.h"
#import "ZDKRMADialogView.h"
#import "ZDKUIViewController.h"


@class ZDKRMA;




/**
 * The ZDKRMADialogViewController manages the two views that make up ZDKRMA.
 */
@interface ZDKRMADialogViewController : ZDKUIViewController <ZDKRMADialogViewDelegate, ZDKRMAFeedbackViewDelegate>


/**
 * A ZDKRMADialogView to be presented.
 */
@property (retain, nonatomic) ZDKRMADialogView *dialog;


/**
 * A ZDKRMAFeedbackView to be presentetd.
 */
@property (retain, nonatomic) ZDKRMAFeedbackView *feedbackView;


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
