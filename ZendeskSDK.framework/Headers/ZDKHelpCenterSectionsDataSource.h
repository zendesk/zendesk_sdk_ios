/*
 *
 *  ZDKHelpCenterSectionsDataSource.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 06/11/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import "ZDKHelpCenterDataSource.h"

@interface ZDKHelpCenterSectionsDataSource : ZDKHelpCenterDataSource

/**
 * Initializes a data source with a categoryId to be used to fetch the sections for the provided categoryId.
 * @param categoryId The categoryId passed from selecting a category
 */

- (instancetype) initWithCategoryId:(NSString *)categoryId ;

@end
