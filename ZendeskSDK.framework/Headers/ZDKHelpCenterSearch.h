/*
 *
 *  ZDKHelpCenterSearch.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/09/2014.
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
 *  This class models a Help Center search.  For more details about Help Centre search please see:
 *  https://developer.zendesk.com/rest_api/docs/help_center/search
 */
@interface ZDKHelpCenterSearch : NSObject

/**
 *  This models the free-form text query
 */
@property (nonatomic) NSString *query;

/**
 *  This models the "label_names" parameter. This will be a comma-separated list of label names to restrict the search to.
 */
@property (nonatomic) NSMutableArray *labelNames;

/**
 *  This models the "locale" parameter. This specifies that the search will be restricted to content with this locale.  The locale
 *  is in the format of "ll-cc", e.g. "en-us".  Locales in the form of "ll" are also permitted, e.g. "en".
 */
@property (nonatomic) NSString *locale;

/**
 *  This models the "include" parameter.  This specifies tne elements to side-load and include in the results.
 */
@property (nonatomic) NSMutableArray *sideLoads;

/**
 *  This models the "category" parameter.  This specifies that the search will be restricted to content that is in the given
 *  category.
 */
@property (nonatomic) NSNumber *categoryId;

/**
 *  This models the "section" parameter.  This specifies that the search will be restricted to content that is in the given 
 *  section.
 */
@property (nonatomic) NSNumber *sectionId;

/**
 *  This models the "page" parameter. This specifies what page of results to return.  This is closely tied to the resultsPerPage
 *  property.
 */
@property (nonatomic) NSNumber *page;

/**
 *  This models the "per_page" parameter.  This specifies how many results to return for the current page.  The current page is
 *  specified by the page property.
 */
@property (nonatomic) NSNumber *resultsPerPage;

/**
 *  This method will return a UTF-8 encoded query string based on the values of the properties of this class.
 *
 *  @return a UTF-8 encoded query string based on the values of the properties of this class.
 */
- (NSString *) asQueryString;

@end
