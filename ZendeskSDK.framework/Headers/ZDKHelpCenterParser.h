/*
 *
 *  ZDKHelpCenterParser.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 17/07/2015.
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
 *  A Help Center Parser class containing static and instance methods to parse json to objects.
 *
 *  @since 1.4.0.1
 */
@interface ZDKHelpCenterParser : NSObject

/**
 *  An NSDictionary of Sections with the key value sectionId.
 *
 *  @since 1.4.0.1
 */
@property (readonly, nonatomic) NSDictionary *sectionLookup;

/**
 *  An NSDictionary of Users with the key value userId.
 *
 *  @since 1.4.0.1
 */
@property (readonly, nonatomic) NSDictionary *userLookup;

/**
 *  An NSDictionary of Categories with the key value categoryId.
 *
 *  @since 1.4.0.1
 */
@property (readonly, nonatomic) NSDictionary *categoryLookup;

/**
 *  Creates an ZDKHelpCentreParser object and parses json dictionary into
 *  categoryLookup, sectionLookup and userLookup properties if they exist in the json.
 *
 *  @since 1.4.0.1
 *
 *  @param dict NSDictionary of sections, categories or articles.
 *  @return An instance of ZDKHelpCentreParser with properities aissigned if they
 *  exist in the json.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;

/**
 *  Parses a json array of Help Center sections.
 *
 *  @since 1.4.0.1
 *
 *  @return A dictionary of ZDKHelpCenterSection objects with sectionId pointers.
 */
+ (NSDictionary *) createSectionLookup:(NSArray *)sectionss;

/**
 *  Parses a json array of Help Center categorys.
 *
 *  @since 1.4.0.1
 *
 *  @return A dictionary of ZDKHelpCenterCategory objects with categoryId pointers.
 */
+ (NSDictionary *) createCategoryLookup:(NSArray *)categories;

/**
 *  Parses a json array of author objects.
 *
 *  @since 1.4.0.1
 *
 *  @return A dictionary of author_name string objects with a userId pointer.
 */
+ (NSDictionary *) createAuthorLookup:(NSArray *)users;

/**
 *  Parses a collection of Help Center json article objects.
 *
 *  @since 1.4.0.1
 *
 *  @return An array of ZDKHelpCenterArticle objects.
 */
- (NSArray *) parseArticles:(NSDictionary *)json;

/**
 *  Parse a collection of Help Center json article objects beginning at root.
 *
 *  @since 1.4.0.1
 *
 *  @param root Root key in json
 *  @return An array of ZDKHelpCenter Article objects.
 */
- (NSArray *) parseArticlesWithRootKey:(NSDictionary *)json withRootKey:(NSString *)root;

/**
 *  Parses a collection of Help Center json article objects, section objects and category objects
 *  into a FlatArticle objects and puts them in alphabetical order.
 *
 *  @since 1.4.0.1
 *
 *  @return An array of ZDKHelpCenterFlatArticle objects.
 */
- (NSArray *) parseFlatArticles:(NSDictionary *)json;

/**
 *  Parses a collection of Help Center search results into an array of article objects.
 *
 *  @since 1.4.0.1
 *
 *  @return An array of ZDKHelpCenterArticle objects.
 */
- (NSArray *) parseArticleSearchResults:(NSDictionary *)json;

@end
