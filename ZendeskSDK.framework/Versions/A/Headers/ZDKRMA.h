//
//  ZDKRMA.h
//  ZendeskSDK
//
//  Created by Zendesk on 25/02/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDKRMAConfigObject.h"
#import "ZDKRMADataObject.h"
#import "ZDKRMADialogViewController.h"
#import "ZDKRMADialogView.h"
#import "ZDKRMAFeedbackView.h"
#import "ZendeskSDKConstants.h"
#import "ZDKAccount.h"


/**
 * ZDKRMA contains interfaces for configuring and displaying a Rate My App dialog.
 * 
 */
@interface ZDKRMA : NSObject


@property (nonatomic, retain, readonly) ZDKRMAConfigObject *zdkrmaConfigObject;
@property (nonatomic, retain, readonly) ZDKRMADataObject *zdkrmaDataObject;


/**
 * Configure ZDKRMA. The configBlock supplies a ZDKRMAConfigObject. Set values on
 * this object to override defaults.
 *
 * @param configBlock a ZDKRMAConfigObject instance. Used to configure ZDKRMA properties.
 */
+ (void) configure:(void (^)(ZDKAccount*, ZDKRMAConfigObject *config))configBlock;


/**
 * To show the ZDKRMA dialog in a view, call this methed in either viewWillAppear or
 * viewDidAppear, or an equivalent method. This will use the shouldShowBlock in ZDKRMAConfigObject to
 * decide if the dialog should be shown.
 *
 * @discussion If ZDKRMA is not properly configure this mithed will log an error and return.
 * @param view A view that RMA will be displayed over.
 */
+ (void) showInView:(UIView*)view;


/**
 * Log a visit. The first call to logVisit sets the initial visitCount and sets the 
 * initialCheckDate. visitCount and initialCheckDate are passed to the shouldShowBlock. 
 * The default shouldShowBlock checks that a threshold of 15 visits has been reached 
 * and that 7 days have past since the initialCheckDate.
 *
 * You should call [ZDKRMA logVisit]; where you want to track user visits. For example
 * to log app visits call [ZDKRMA logVisit]; in the following app delegate methods:
 *
 * - (void) applicationWillEnterForeground:(UIApplication*)application;
 *
 * - (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;
 * 
 * If you use the default ZDKRMA setup you need to include a call to logVisit somewhere in your code.
 *
 */
+ (void) logVisit;


/**
 * If using a custom sendFeedbackBlock this method must be invoked to exit the spinner 
 * state of the feedback view and transition to the success state.
 */
+ (void) notifyFeedbackSuccess;


/**
 * If using a custom sendFeedbackBlock this method must be invoked to exit the spinner 
 * state of the feedback view and transition to the error state.
 */
+ (void) notifyFeedbackError;



@end
