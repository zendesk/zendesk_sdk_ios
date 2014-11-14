//
//  ZDKHelpCenterArticlesByLabelDataSource.h
//  ZendeskSDK
//
//  Created by Zendesk on 06/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <ZendeskSDK/ZendeskSDK.h>

@interface ZDKHelpCenterArticlesByLabelDataSource : ZDKHelpCenterDataSource

/**
 * Initializes a data source with an array of labels to filter the list of articles to be shown.
 * @param articleLabels The articleLabels passed as an array of Strings of possible labels to filter by
 */

- (instancetype) initWithArticleLabels:(NSArray *)articleLabels ;


@end
