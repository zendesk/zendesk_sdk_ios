/*
 *
 *  ZDKHelpCenterProvide.h
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

#import <Foundation/Foundation.h>

/**
 * Callback block.
 *
 */
typedef void (^ZDKHelpCenterCallback)(NSArray *items, NSError *error);

@interface ZDKHelpCenterProvider : NSObject

/**
 *  Fetch a list of categories from a Help Center instance.
 *
 *  @param callback Callback that will deliver a list of categories available on the instance of the Help Center for the provided locale
 */
- (void) getCategoriesWithCallback:(ZDKHelpCenterCallback)callback;

/**
 *  Fetch a list of sections for a given categoryId from a Help Center instance
 *
 *  @param categoryId NSString to specify what sections should be returned, only sections belonging to the category will be returned
 *  @param callback   Callback that will deliver a list of sections available on the instance of the Help Center for the provided locale and categoryId
 */
- (void) getSectionsForCategoryId: (NSString *) categoryId withCallback:(ZDKHelpCenterCallback) callback;

/**
 *  Fetch a list of articles for a given sectionId from a Help Center instance
 *
 *  @param sectionId NSString to specify what articles should be returned, only articles belonging to the section will be returned
 *  @param callback  Callback that will deliver a list of articles available on the instance of the Help Center for the provided locale and sectionId
 */
- (void) getArticlesForSectionId:(NSString *) sectionId withCallback: (ZDKHelpCenterCallback) callback;

/**
 *  This method will search articles in your Help Center.
 *  This method will also sideload categories, sections and users.
 *
 *  @param query    The query text used to perform the search
 *  @param callback The callback which will be called upon a successful or an erroneous response.
 */
- (void) searchForArticlesUsingQuery:(NSString *)query withCallback: (ZDKHelpCenterCallback) callback;

/**
 *  This method will search articles in your Help Center filtered by an array of labels
 *
 *  @param query    The query text used to perform the search
 *  @param labels   The array of labels used to filter the search results
 *  @param callback The callback which will be called upon a successful or an erroneous response.
 */
- (void) searchForArticlesUsingQuery:(NSString *)query andLabels:(NSArray *)labels withCallback: (ZDKHelpCenterCallback) callback;

/**
 *  This method returns a list of attachments for a single article.
 *
 *  @param articleId the identifier to be used to retrieve an article from a Help Center instance
 *  @param callback  the callback that is invoked when a request is either successful or has errors
 */
- (void) getAttachmentForArticleId:(NSString *)articleId withCallback: (ZDKHelpCenterCallback) callback;

/**
 *  Fetch a list of articles for a given array of labels from a Help Center instance
 *
 *  @param labels   an array of labels used to filter articles by
 *  @param callback the callback that is invoked when a request is either successful or has errors
 */
- (void) getArticlesByLabels:(NSArray *)labels withCallback: (ZDKHelpCenterCallback) callback;

@end
