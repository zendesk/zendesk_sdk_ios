/*
 *
 *  ZDKHelpCenterCategoriesDataSource.h
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
 *  Data source for Help Center categories.
 *
 *  @since 0.9.3.1
 */
@interface ZDKHelpCenterCategoriesDataSource : ZDKHelpCenterDataSource


/**
 *  Initializes a data source and fetches the categories for the configured Zendesk instance.
 *
 *  @since 0.9.3.1
 *
 *  @return A new instance.
 */
- (instancetype) init;


@end
