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



@interface ZDKHelpCenterArticle : NSObject

@property (strong, nonatomic) NSString *sid;
@property (strong, nonatomic) NSString *section_id;
@property (strong, nonatomic) NSString *title;
@property (strong, nonatomic) NSString *body;
@property (strong, nonatomic) NSString *author_name;
@property (strong, nonatomic) NSString *author_id;
@property (strong, nonatomic) NSString *article_details;
@property (strong, nonatomic) NSString *articleParents;
@property (strong, nonatomic) NSDate *created_at;
@property (assign, nonatomic) NSInteger position;
@property (assign, nonatomic) BOOL outdated;



/**
 * Parses a single Help Center json article object.
 *
 * @return A new ZDKHelpCenterArticle.
 */
+ (ZDKHelpCenterArticle *) parseArticle:(NSDictionary *)articleJson;


/**
 * Parses a collection of Help Center json article objects.
 *
 * @return An array of ZDKHelpCenterArticle objects.
 */
+ (NSArray *) parseArticles:(NSDictionary *)json;


/**
 * Parses a collection of Help Center search results into an array of article objects.
 *
 * @return An array of ZDKHelpCenterArticle objects.
 */
+ (NSArray *) parseArticleSearchResults:(NSDictionary *)json;


/**
 * Parse a collection of Help Center json article objects beginning at root
 *
 * @param root Root key in json
 * @return An array of ZDKHelpCenter Article objects.
 */
+ (NSArray *) parseArticlesWithRootKey:(NSDictionary *)json withRootKey:(NSString *)root;


@end
