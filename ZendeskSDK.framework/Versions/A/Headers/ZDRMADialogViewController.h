//
//  ZDRateMyApp.h
//  ZDRateMyApp
//
//  Created by Zendesk on 19/02/2014.
//  Copyright (c) 2014 Alan Egan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZDRMAFeedbackView.h"
#import "ZDRMADialogView.h"
#import "ZDUI.h"

@class ZDRMA;

/**
  * Posted immediately prior to the dismissal of RMA dialog.
 */
extern NSString * const ZDRMAWillHideDialogNotification;

extern NSString * const ZDRMAShouldStoreActionNotification;

extern NSString * const ZDRMAShouldSendFeedbackNotification;

/**
 * The ZDRMADialogViewController manages the two views that make up ZDRMA.
 */
@interface ZDRMADialogViewController : ZDUIUIViewController <ZDRMADialogViewDelegate, ZDRMAFeedbackViewDelegate>


/**
 * A ZDRMADialogView to be presented.
 */
@property (retain, nonatomic) ZDRMADialogView *dialog;


/**
 * A ZDRMAFeedbackView to be presentetd.
 */
@property (retain, nonatomic) ZDRMAFeedbackView *feedbackView;


/**
 * Initializes and returns a ZDRMADialogViewController.
 *
 * This creates a ZDRMADialogViewController.
 *
 * @param zdrma The instance of ZDRMA. 
 * @return An initialized ZDRMADialogViewController.
 *
 */
- (instancetype) initWithConfig:(ZDRMAConfigObject*)config;

@end
