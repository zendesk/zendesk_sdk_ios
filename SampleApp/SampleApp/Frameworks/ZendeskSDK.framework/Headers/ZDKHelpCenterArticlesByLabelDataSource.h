/*
 *
 *  ZDKHelpCenterArticlesByLabelDataSource.h
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

@interface ZDKHelpCenterArticlesByLabelDataSource : ZDKHelpCenterDataSource

/**
 * Initializes a data source with an array of labels to filter the list of articles to be shown.
 * @param articleLabels The articleLabels passed as an array of Strings of possible labels to filter by
 */

- (instancetype) initWithArticleLabels:(NSArray *)articleLabels;


@end
