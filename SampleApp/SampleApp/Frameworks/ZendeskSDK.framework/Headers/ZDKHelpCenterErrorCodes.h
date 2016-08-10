/*
 *
 *  ZDKHelpCenterErrorCodes.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 30/05/2016.
 *
 *  Copyright © 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>


/**
 *  Help Center error codes.
 */
typedef NS_ENUM(NSUInteger, ZDKHelpCenterError) {
    
    /**
     *  Category ids were not found in Help Center.
     */
    ZDKHelpCenterErrorInvalidCategoryIds = 100,
    
    /**
     *  Section ids were not found in Help Center.
     */
    ZDKHelpCenterErrorInvalidSectionIds,
    
    /**
     *  No articles were found with the specified labels.
     */
    ZDKHelpCenterErrorNoArticlesForLabels,
    
    /**
     *  Help Center has no content.
     */
    ZDKHelpCenterErrorEmptyHelpCenter
};

/**
 *  Help Center error domain.
 */
extern NSString * const ZDKHelpCenterErrorDomain;

/**
 *  Error description for category id error.
 */
extern NSString * const ZDKHelpCenterNoCategoriesLocalisedDescription;

/**
 *  Error description for section id error.
 */
extern NSString * const ZDKHelpCenterNoSectionsLocalisedDescription;

/**
 *  Error description for label error.
 */
extern NSString * const ZDKHelpCenterNoArticlesForLabelsDescription;

/**
 *  Error description for empty Help Center.
 */
extern NSString * const ZDKHelpCenterEmptyHelpCenterDescription;
