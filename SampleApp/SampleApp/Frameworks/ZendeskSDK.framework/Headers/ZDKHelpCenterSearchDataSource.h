/*
 *
 *  ZDKHelpCenterSearchDataSource.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 07/11/2014.  
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

@interface ZDKHelpCenterSearchDataSource : ZDKHelpCenterDataSource

/**
 *  init with search query
 *
 *  @param query NSString search query to be sent to Help Center instance *
 *  @return instance of data source
 */
- (instancetype) initWithQuery:(NSString *)query;

/**
 *  init with search query and labels
 *
 *  @param query NSString search query to be sent to Help Center instance
 *  @param labels NSArray of Strings, used to filter search query with additional labels
 *
 *  @return instance of data source
 */
- (instancetype) initWithQuery:(NSString *)query andLabels:(NSArray *)labels;

@end
