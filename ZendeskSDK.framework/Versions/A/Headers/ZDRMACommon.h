//
//  ZDRMACommon.h
//  ZDRateMyApp
//
//  Created by Zendesk on 20/02/2014.
//  Copyright (c) 2014 Alan Egan. All rights reserved.
//

#import <UIKit/UIKit.h>


// itunes link formats
static NSString *const iOS7AppStoreURLFormat = @"itms-apps://itunes.apple.com/app/id%d";
static NSString *const iOSAppStoreURLFormat = @"itms-apps://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%d";

// zendesk request submission strings
static NSString *const ZDRMAZendeskURL = @"https:/%@.zendesk.com/requests/mobile_api/create";
static NSString *const ZDRMARequestFeedbackTag = @"ratemyapp_feedback";
static NSString *const ZDRMARequestIOSTag = @"ratemyapp_ios";
static NSString *const ZDRMARequestBuildVariantTag = @"ratemyapp_ios_%@";
static NSString *const ZDRMAPostString = @"set_tags=%@&description=%@&email=%@&subject=%@";
static NSString *const ZDRMAMobileApiHTTPHeader = @"X-Zendesk-Mobile-API";
static NSString *const ZDRMAMobileApiVersion = @"1.0";

// persistence keys
static NSString *const ZDRMAChosenAction = @"ZDRMAChosenAction";
static NSString *const ZDRMADateOfActionChosen = @"ZDRMADateOfActionChosen";
static NSString *const ZDRMAAppVersion= @"ZDRMAAppVersionChosen";
static NSString *const ZDRMAVisitCount = @"ZDRMAVisitCount";
static NSString *const ZDRMAInitialCheckDate = @"ZDRMAInitialCheckDate";
static NSString *const ZDRMARequestText = @"ZDRMATicketText";

// default accessibility id
static NSString *const ZDRMAAccessibilityID = @"ZDRMAAccessibilityID";


/**
 * ZDRMACommon contains string constants use throughout ZDRMA.
 *
 */
@interface ZDRMACommon : NSObject

@end
