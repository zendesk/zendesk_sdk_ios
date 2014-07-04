//
// Created by Zendesk on 31/03/2014.
// Copyright (c) 2014 Alan Egan. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * A ZDRMAAction describes the actions available for Rate My App.
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
 * @see - arrayWithZDRMAActions:
 *
 */
typedef NS_ENUM(NSInteger, ZDRMAAction) {

    /**
     * Enumeration for rating an app.
     */
    ZDRMARateApp        = 1,

    /**
     * Enumeration for sending feedbcak.
     */
    ZDRMASendFeedback   = 2,

    /**
     * Enumeration for choosing to never be prompted for feedback again.
     */
    ZDRMADontAskAgain   = 3,

    /**
     * Enumeration for an undisplayed option.
     */
    ZDRMAUndisplayed    = 4
};




/**
 * ZDRMADataObject holds the persisted data used in ZDRMA. Setting a value
 * on ZDRMADataObject sets a corresponding value in NSUserDefaults.
 */
@interface ZDRMADataObject : NSObject


/**
 * A ZDRMAAction value for the current state of the ZDRMA dialog.
 * If ZDRMA has not been displayed the default value is ZDRMAUndisplayed.
 */
@property (nonatomic, assign) ZDRMAAction chosenZDRMAAction;


/**
 * The number of times a user has visited the view in which ZDRMA is to be displayed.
 */
@property (nonatomic, retain) NSNumber *visitCount;


/**
 * The date of the first time ZDRMA showInView was called.
 */
@property (nonatomic, retain) NSDate *initialCheckDate;


/**
 * The date of the users intereaction with the ZDRMA dialog.
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
 * Initializes and returns a ZDRMADataObject.
 *
 * This creates a ZDRMADataObject with values from standard user defaults.
 *
 *
 * @return An initialized ZDRMADataObject.
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
 * Takes the give ZDRMA action and stores this along with the current date and app version. 
 *
 * @param action The ZDRMAAction to store.
 */
- (void) storeChosenAction:(ZDRMAAction)action;


@end