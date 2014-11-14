//
//  ZDKHelpCenterArticlesDataSource.h
//  ZendeskSDK
//
//  Created by Zendesk on 06/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <ZendeskSDK/ZendeskSDK.h>

@interface ZDKHelpCenterArticlesDataSource : ZDKHelpCenterDataSource

/**
 * Initializes a data source with a sectionId to fetch articles for that sectionId.
 * @param sectionId The sectionId passed from selecting a category
 */

- (instancetype) initWithSectionId:(NSString *)sectionId;

@end
