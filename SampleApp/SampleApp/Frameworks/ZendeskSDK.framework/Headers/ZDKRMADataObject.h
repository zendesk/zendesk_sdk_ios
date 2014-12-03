/*
 *
 *  ZDKRMADataObject.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 31/03/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>


/**
 * A ZDKRMAAction describes the actions available for Rate My App.
 * The dialog options are specified with a combination of these actions.
 *
 * Each action is mapped to localizable string key which is used for the
 * title of the coresponding option in the dialog view:
 *
 * ios.RMA.dialog.rateApp.button
 *
 * ios.RMA.dialog.sendFeedback.button
 *
 * ios.RMA.dialog.dismiss.button
 *
 * @see - arrayWithZDKRMAActions:
 *
 */
typedef NS_ENUM(NSInteger, ZDKRMAAction) {

    /**
     * Enumeration for rating an app.
     */
    ZDKRMARateApp        = 1,

    /**
     * Enumeration for sending feedbcak.
     */
    ZDKRMASendFeedback   = 2,

    /**
     * Enumeration for choosing to never be prompted for feedback again.
     */
    ZDKRMADontAskAgain   = 3,

    /**
     * Enumeration for an undisplayed option.
     */
    ZDKRMAUndisplayed    = 4
};




/**
 * ZDKRMADataObject holds the persisted data used in ZDKRMA. Setting a value
 * on ZDKRMADataObject sets a corresponding value in NSUserDefaults.
 */
@interface ZDKRMADataObject : NSObject


/**
 * A ZDKRMAAction value for the current state of the ZDKRMA dialog.
 * If ZDKRMA has not been displayed the default value is ZDKRMAUndisplayed.
 */
@property (nonatomic, assign) ZDKRMAAction chosenZDKRMAAction;


/**
 * The number of times a user has visited the view in which ZDKRMA is to be displayed.
 */
@property (nonatomic, retain) NSNumber *visitCount;


/**
 * The date of the first time ZDKRMA showInView was called.
 */
@property (nonatomic, retain) NSDate *initialCheckDate;


/**
 * The date of the users intereaction with the ZDKRMA dialog.
 */
@property (nonatomic, retain) NSDate *dateOfActionChosen;


/**
 * The text from the feedback view. This should be nil unless there
 * was an error sending the feedback.
 *
 */
@property (nonatomic, retain) NSString *requestText;

/**
 * The app version of at the time of intereaction.
 *
 */
@property (nonatomic, retain) NSString *appVersion;


/**
 * Initializes and returns a ZDKRMADataObject.
 *
 * This creates a ZDKRMADataObject with values from standard user defaults.
 *
 *
 * @return An initialized ZDKRMADataObject.
 *
 */
- (instancetype) init;


/**
 * A wrapper for extracting the CFBundleShortVersionString from main bundle's info dictionary.
 *
 * @return currentAppVersion String representation of the current app version (CFBundleShortVersionString).
 */
+ (NSString*) currentAppVersion;


/**
 * A wrapper for extracting the CFBundleVersion from main bundle's info dictionary.
 *
 * @return currentAppBuild String representation of the current build (CFBundleVersion).
 */
+ (NSString*) currentAppBuild;


/**
 * Takes the give ZDKRMA action and stores this along with the current date and app version. 
 *
 * @param action The ZDKRMAAction to store.
 */
- (void) storeChosenAction:(ZDKRMAAction)action;


@end
