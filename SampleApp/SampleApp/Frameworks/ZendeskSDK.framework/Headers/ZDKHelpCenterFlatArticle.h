/*
 *
 *  ZDKHelpCenterFlatArticle.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 17/07/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKHelpCenterArticle.h"
#import "ZDKHelpCenterCategory.h"
#import "ZDKHelpCenterSection.h"

/**
 *  A Help Center FlatArticle.
 *
 *  @since 1.4.0.1
 */
@interface ZDKHelpCenterFlatArticle : NSObject

/**
 *  An Article object.
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) ZDKHelpCenterArticle *article;

/**
 *  A Section object.
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) ZDKHelpCenterSection *section;

/**
 *  A Category object.
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) ZDKHelpCenterCategory *category;

/**
 *  Get a string of an article's breadcrumb(i.e. it's relevant section and category).
 *
 *  @since 1.4.0.1
 *
 *  @return A string with the article's name, followed by it's section name and category name.
 */
- (NSString *) getArticleBreadcrumb;


@end
