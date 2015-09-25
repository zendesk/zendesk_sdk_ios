/*
 *
 *  ZDKRMAConfigObject.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 24/03/2014.  
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
#import "ZDKRMADataObject.h"


/**
 * A block to decide whether to show the Rate My App dialog. Returning YES will show the Rate My App dialog.
 *
 * @param visitCount the number of times a user has visited the view which Rate My App will be dislayed on top of.
 * @param initialCheckDate the date which ShouldShow was first run.
 * @param lastDisplayDate the date Rate My App was last displayed.
 * @param lastOptionSelected the action chosen the last time Rate My App was shown.
 * @param appVersionAtLastInteraction the version of the app when Rate My App was last shown.
 *
 * @return Returning YES causes the Rate My App dialog to be displayed. NO causes nothing to be displayed.
 */
typedef BOOL (^ShouldShow) (NSNumber *visitCount, NSDate *initialCheckDate, NSDate *lastDisplayDate, ZDKRMAAction lastOptionSelected, NSString *appVersionAtLastInteraction);


/**
 * A block for sending the description in ZDKRMAFeedbackView to some endpoint. The default behaviour creates a request
 * using the zendesk subdomain in ZDKRMA.
 *
 * @param feedback The contents of the text view in ZDKRMAFeedbackView.
 */
typedef void (^SendFeedback) (NSString *feedback);


/**
 * A success block for SendFeedback.
 */
typedef void (^SendFeedbackSuccess) (void);


/**
 * An error block for SendFeedback.
 */
typedef void (^SendFeedbackError) (void);


/**
 *
 * ZDKRMAConfigObject encapsulates the configurable properties of ZDKRMA. A 
 * ZDKRMAConfigObject is supplied to the ZDKRMA configure method:
 *
 * @see + configure: in ZDKRMA.h
 * 
 * To override the default settings of ZDKRMA, call the configure method and 
 * set new values as desired.
 *
 */
@interface ZDKRMAConfigObject : NSObject <NSCopying>


/**
 *
 * Is RMA enabled.
 *
 */
@property (nonatomic, readonly, getter = isEnabled) BOOL enabled;


/**
 *
 * A threshold for visit count. By default minimumVisits in conjunction with
 * minimumDays are set to ensure that an app has been used enough for a rating
 * to be of value.
 *
 * The default value is 15.
 *
 */
@property (nonatomic, strong, readonly) NSNumber *minimumVisits;

/**
 * A threshold in days since the initial call to logVisit. By default minimumDays 
 * in conjunction with minimumVisits are set to ensure that an app has been used
 * enough for a rating to be of value.
 *
 * The default value is 7.
 */
@property (nonatomic, strong, readonly) NSNumber *minimumDays;

/**
 * Your itunes app id. This is used to link to the app store.
 * You must set this in the configure method of ZDKRMA.
 *
 * Default value is nil.
 */
@property (nonatomic, strong, readonly) NSString *itunesAppId;

/**
 * The delay in seconds between a call to [ZDKRMA showInView:view] and ZDKRMA 
 * being displayed.
 *
 * The default value is 2.0.
 */
@property (nonatomic, strong, readonly) NSNumber *displayDelay;


/**
 * Tags to be set on the new request.
 *
 * Default value is set in the lotus config. These tags are concatinated with additionalTags.
 */
@property (nonatomic, strong, readonly) NSArray *serverConfigTags;


/**
 * Additional tags to be set on the new request.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSArray *additionalTags;

/**
 * Additional info to be included in the new request, this will be added 
 * above the device info and below the user request.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSString *additionalRequestInfo;

/**
 * An array that specifies the options in the dialog view.
 *
 * @see - arrayWithZDKRMAActions:
 *
 * Default value is @[ZDKRMARateApp, ZDKRMASendFeedback, ZDKRMADontAskAgain]
 */
@property (nonatomic, strong) NSArray *dialogActions;

/**
 * The name of the image shown on successful feedback submission. The image will
 * be centred in the available area, which is 500 x 160. Images larger than this
 * will be cropped.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSString *successImageName;

/**
 * The name of the image shown feedback submission fails. The image will
 * be centred in the available area, which is 500 x 160. Images larger than this
 * will be cropped.
 *
 * Default value is nil.
 */
@property (nonatomic, strong) NSString *errorImageName;

/**
 * A block that is responsible for deciding whether Rate My App is shown or not.
 * When a call to [ZDKRMA showInView:view] is made, this block is invoked.
 *
 * Returning YES results in Rate My App being shown. Returning NO will mean 
 * Rate My App is not shown. Can be overridden for custom behaviour.
 * 
 * Default implementation returns YES if the visitCount is greater than 
 * minimumVisitCount and days since initialCheckDate is greater than 
 * minimumDays, and returns NO otherwise.
 *
 */
@property (nonatomic, copy) ShouldShow shouldShowBlock;

/**
 * A block that is invoked when the "Send feedback" button is pressed. 
 *
 * The default implementation creates a request with the Zendesk account specified 
 * by zendeskSubdomain and userEmail.
 *
 */
@property (nonatomic, copy) SendFeedback sendFeedbackBlock;


/**
 * Helper method which builds an array from ZDKRMAActions. This determines what actions
 * are displayed in the dialog view. The order in which they are specified in the list is 
 * the order that they will appear in the dialog.
 *
 * This is used during the initialisation of ZDKRMAConfigObject to set the default values 
 * of the dialogActions property.
 *
 * @see ZDKRMAAction, dialogActions.
 *
 * @param action A comma sepporated list of ZDKRMAAtion values with a nil terminator.
 * @return An array of ZDKRMAActions as NSNumbers.
 */
+ (NSArray*) arrayWithZDKRMAActions:(ZDKRMAAction) action, ...;


/**
 * A helper method that calculates the number of days between two NSDate object.
 *
 * @param fromDate The start date.
 * @param toDate The end date.
 * @return The number of days between the dates.
 */
+ (NSInteger) daysBetweenDate:(NSDate*)fromDate andDate:(NSDate*)toDate;


/**
 * A helper method that concatenates the server config tags with the additional tags.
 *
 * @return An array containing all tags in serverConfigTags and additionalTags.
 */
- (NSArray *) tagList;

@end
