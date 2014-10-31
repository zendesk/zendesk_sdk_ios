//
//  ZDKHelpCenterArticle.h
//  ZendeskSDK
//
//  Created by Zendesk on 25/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

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


@end
