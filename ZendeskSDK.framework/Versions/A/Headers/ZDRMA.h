//
//  ZDRMA.h
//  ZDRateMyApp
//
//  Created by Zendesk on 25/02/2014.
//  Copyright (c) 2014 Alan Egan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDRMAConfigObject.h"
#import "ZDRMADataObject.h"
#import "ZDRMADialogViewController.h"
#import "ZDRMADialogView.h"
#import "ZDRMAFeedbackView.h"
#import "ZDRMACommon.h"

/**
 * ZDRMA contains interfaces for configuring and displaying a Rate My App dialog.
 * 
 */
@interface ZDRMA : NSObject


@property (nonatomic, retain, readonly) ZDRMAConfigObject *zdrmaConfigObject;
@property (nonatomic, retain, readonly) ZDRMADataObject *zdrmaDataObject;


/**
 * Configure ZDRMA. The configBlock supplies a ZDRMAConfigObject. Set values on
 * this object to override defaults.
 *
 * @param configBlock a ZDRMAConfigObject instance. Used to configure ZDRMA properties.
 */
+ (void) configure:(void (^)(ZDRMAConfigObject *config))configBlock;


/**
 * To show the ZDRMA dialog in a view, call this methed in either viewWillAppear or
 * viewDidAppear, or an equivalent method. This will use the shouldShowBlock in ZDRMAConfigObject to
 * decide if the dialog should be shown.
 *
 * @discusion If ZDRMA is not properly configure this mithed will log an error and return.
 * @param view A view that RMA will be displayed over.
 */
+ (void) showInView:(UIView*)view;


/**
 * Log a visit. The first call to logVisit sets the initial visitCount and sets the 
 * initialCheckDate. visitCount and initialCheckDate are passed to the shouldShowBlock. 
 * The default shouldShowBlock checks that a threshold of 15 visits has been reached 
 * and that 7 days have past since the initialCheckDate.
 *
 * You should call [ZDRMA logVisit]; where you want to track user visits. For example
 * to log app visits call [ZDRMA logVisit]; in the following app delegate methods:
 *
 * - (void) applicationWillEnterForeground:(UIApplication*)application;
 *
 * - (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;
 * 
 * If you use the default ZDRMA setup you need to include a call to logVisit somewhere in your code.
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
