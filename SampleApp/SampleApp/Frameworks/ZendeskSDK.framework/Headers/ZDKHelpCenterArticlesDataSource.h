/*
 *
 *  ZDKHelpCenterArticlesDataSource.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 06/11/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import "ZDKHelpCenterDataSource.h"


/**
 *  Help Center article datasource.
 *
 *  @since 0.9.3.1
 */
@interface ZDKHelpCenterArticlesDataSource : ZDKHelpCenterDataSource


/**
 *  Initializes a data source with a sectionId to fetch articles for that sectionId.
 *
 *  @since 0.9.3.1
 *
 *  @param sectionId The sectionId passed from selecting a category
 */
- (instancetype) initWithSectionId:(NSString *)sectionId;


@end
