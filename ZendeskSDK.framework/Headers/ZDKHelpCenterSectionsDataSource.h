//
//  ZDKHelpCenterSectionsDataSource.h
//  ZendeskSDK
//
//  Created by Zendesk on 06/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <ZendeskSDK/ZendeskSDK.h>

@interface ZDKHelpCenterSectionsDataSource : ZDKHelpCenterDataSource

/**
 * Initializes a data source with a categoryId to be used to fetch the sections for the provided categoryId.
 * @param categoryId The categoryId passed from selecting a category
 */

- (instancetype) initWithCategoryId:(NSString *)categoryId ;

@end
