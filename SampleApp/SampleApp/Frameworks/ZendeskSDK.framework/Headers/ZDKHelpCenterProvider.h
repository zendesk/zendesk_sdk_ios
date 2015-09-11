/*
 *
 *  ZDKHelpCenterProvider.h
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
#import "ZDKHelpCenterSearch.h"
#import "ZDKHelpCenterDeflection.h"

/**
 * Callback block.
 *
 */
typedef void (^ZDKHelpCenterCallback)(NSArray *items, NSError *error);


/**
 *  Callback for Help Center simple responses, i.e. Status codes.
 *
 *  @since 1.3.0.1
 *
 *  @param response The response for a request
 *  @param error    An error, nil if no error occurred.
 */
typedef void (^ZDKHelpCenterGenericCallback)(id response, NSError *error);


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
 *  This method will search articles in your Help Center filtered by the parameters in the given ZDKHelpCenterSearch model.
 *  
 *  @param search   The search to perform.
 *  @param callback The callback which will be called upon a successful or an erroneous response.
 *  @see <a href="https://developer.zendesk.com/rest_api/docs/help_center/search">Searching Help Center.</a>
 */
- (void) searchArticles:(ZDKHelpCenterSearch*) search withCallback: (ZDKHelpCenterCallback) callback;

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

/**
 *  Fetch an article by ID.
 *
 *  @param articleId The ID of the article to fetch.
 *  @param callback  The callback that is invoked when a request is either successful or has error.
 *
 *  @since 1.3.1.1
 */
- (void) getArticleById:(NSString *)articleId withCallback:(ZDKHelpCenterCallback) callback;


/**
 *  Fetch a list of suggested articles filtered by the parameters in the given ZDKHelpCenterDeflection model.
 *
 *  @since 1.2.0.1
 *
 *  @param search   The search to preform
 *  @param callback The callback that is invoked when a request is either successful or has error.
 */
- (void) getSuggestedArticles:(ZDKHelpCenterDeflection*)search withCallback:(ZDKHelpCenterCallback)callback;

/**
 *  Fetch a list of FlatArticle objects for a given Help Center instance.
 *
 *  @since 1.4.0.1
 *
 *  @param callback The callback that is invoked when a request is either successful or has error.
 */
- (void) getFlatArticlesWithCallback:(ZDKHelpCenterCallback)callback;

/**
 *  Fetches a section object for a particluar sectionId.
 *
 *  @since 1.4.0.1
 *
 *  @param sectionId The id of the section to fetch.
 *  @param callback The callback that is invoked when a request is either successful or has error.
 */
- (void) getSectionById:(NSString *)sectionId withCallback:(ZDKHelpCenterCallback)callback;

/**
 *  Fetches a category object for a particluar categoryId.
 *
 *  @since 1.4.0.1
 *
 *  @param categoryId The id of the section to fetch.
 *  @param callback The callback that is invoked when a request is either successful or has error.
 */
- (void) getCategoryById:(NSString *)categoryId withCallback:(ZDKHelpCenterCallback)callback;

/**
 *  Used for the purpose of reporting in Zendesk. This will record an article as being viewed by the client. 
 *
 *  @since 1.3.0.1
 *
 *  @param articleId     The id of the article which has been viewed.
 *  @param articleLocale The locale of the article.
 *  @param callback      A completion callback. Can be nil.
 */
- (void) submitRecordArticleView:(NSString*)articleId locale:(NSString*)articleLocale withCallback:(ZDKHelpCenterGenericCallback)callback;


/**
 *  Post an upvote for a given article. If a vote already exists for the source object it is updated.
 *
 *  @since 1.3.0.1
 *
 *  @param articleId The id of the article to upvote.
 *  @param callback  The callback that is invoked when a request is either successful or has error. Returns the vote object.
 */
- (void) upvoteArticleWithId:(NSString *)articleId withCallback:(ZDKHelpCenterCallback)callback;


/**
 *  Post a downvote for a given article. If a vote already exists for the source object it is updated.
 *
 *  @since 1.3.0.1
 *
 *  @param articleId The id of the article to upvote.
 *  @param callback  The callback that is invoked when a request is either successful or has error. Returns the vote object.
 */
- (void) downvoteArticleWithId:(NSString *)articleId withCallback:(ZDKHelpCenterCallback)callback;


/**
 *  Deletes a vote for a given id
 *
 *  @since 1.3.0.1
 *
 *  @param voteId The id of the vote to delete
 *  @param callback  The callback that is invoked when a request is either successful or has error. Returns a status code
 */
- (void) deleteVoteWithId:(NSString*)voteId withCallback:(ZDKHelpCenterGenericCallback)callback;


@end
