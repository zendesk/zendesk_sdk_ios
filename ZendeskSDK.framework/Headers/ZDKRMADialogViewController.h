//
//  ZDKRMADialogViewController.h
//  ZendeskSDK
//
//  Created by Zendesk on 19/02/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

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
