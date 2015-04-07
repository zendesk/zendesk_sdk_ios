/*
 *
 *  ZDKHelpCenterArticle.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

/**
 *  A Help Center Article.
 *
 *  @since 0.9.3.1
 */
@interface ZDKHelpCenterArticle : NSObject

/**
 *  Article id.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *sid;

/**
 *  Section id.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *section_id;

/**
 *  Article title.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *title;

/**
 *  Content of the article.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *body;


/**
 *  Author of the article.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *author_name;

/**
 *  Id of the author.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *author_id;

/**
 *  Appears at the end of an article, contains the author name and creation date.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *article_details;

/**
 *  A string containing the category and section an article belongs to.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *articleParents;

/**
 *  Creation date for an article.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSDate *created_at;

/**
 *  The articles position in it's parent section.
 *
 *  @since 0.9.3.1
 */
@property (assign, nonatomic) NSInteger position;

/**
 *  Is the article outdated?
 *
 *  @since 0.9.3.1
 */
@property (assign, nonatomic) BOOL outdated;



/**
 *  Parses a single Help Center json article object.
 *
 *  @since 0.9.3.1
 *
 *  @return A new ZDKHelpCenterArticle.
 */
+ (ZDKHelpCenterArticle *) parseArticle:(NSDictionary *)articleJson;


/**
 *  Parses a collection of Help Center json article objects.
 *
 *  @since 0.9.3.1
 *
 *  @return An array of ZDKHelpCenterArticle objects.
 */
+ (NSArray *) parseArticles:(NSDictionary *)json;


/**
 *  Parses a collection of Help Center search results into an array of article objects.
 *
 *  @since 0.9.3.1
 *
 *  @return An array of ZDKHelpCenterArticle objects.
 */
+ (NSArray *) parseArticleSearchResults:(NSDictionary *)json;


/**
 *  Parse a collection of Help Center json article objects beginning at root
 *
 *  @since 0.9.3.1
 *
 *  @param root Root key in json
 *  @return An array of ZDKHelpCenter Article objects.
 */
+ (NSArray *) parseArticlesWithRootKey:(NSDictionary *)json withRootKey:(NSString *)root;


@end
