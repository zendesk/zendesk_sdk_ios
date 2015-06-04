/*
 *
 *  ZDKHelpCenterSimpleArticle.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 3/31/15.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 * By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 * of Service ( https://www.zendesk.com/company/terms ) and Application Developer and API License
 * Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 * acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

/**
 *  This is a model object for a simple article returned by the suggested article provider
 *  @see ZDKHelpCenterProvider.h
 *  @since 1.2.0.1
 */
@interface ZDKHelpCenterSimpleArticle : NSObject

/**
 *  The article ID.
 *  @since 1.2.0.1
 */
@property (nonatomic, strong) NSString *id;

/**
 *  The article title.
 *  @since 1.2.0.1
 */
@property (nonatomic, strong) NSString *title;

/**
 *  Parse a collection of simple articles returned by the suggested articles provider.
 *  @since 1.2.0.1
 */
+ (NSArray *) parseDeflectionSearchResults:(NSDictionary *)json;


/**
 *  Parse a single simple article object.
 *  @since 1.2.0.1
 */
+ (ZDKHelpCenterSimpleArticle *) parseSimpleArticle:(NSDictionary *)simpleArticleJSON;



@end
