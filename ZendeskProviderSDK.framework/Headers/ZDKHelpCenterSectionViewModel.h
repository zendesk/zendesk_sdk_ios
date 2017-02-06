/*
 *
 *  ZDKHelpCenterSectionViewModel.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 11/05/2016.
 *
 *  Copyright © 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKHelpCenterViewModel.h"

@class ZDKHelpCenterArticleViewModel;

@interface ZDKHelpCenterSectionViewModel : NSObject <ZDKHelpCenterViewModel>

/**
 *  Section id.
 */
@property (nonatomic, copy) NSString *sectionId;

/**
 *  Category id for section.
 */
@property (nonatomic, copy) NSString *categoryId;

/**
 *  section name.
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Total number of articles in the section.
 */
@property (nonatomic, strong) NSNumber *totalNumberOfArticles;

/**
 *  Array of articles contained within the section
 */
@property (nonatomic, copy) NSArray<ZDKHelpCenterArticleViewModel *> *articles;

/**
 *  Parses returned json to sections
 *
 *  @param json The Json passed into it
 *
 *  @return An array of help center sections
 */
+ (NSArray<ZDKHelpCenterSectionViewModel *> *)parseSections:(NSDictionary *)json;

/**
 *  Parses json to a single section
 *
 *  @param json The json to be parsed
 *
 *  @return a basic article
 */
+ (ZDKHelpCenterSectionViewModel *)parseSection:(NSDictionary *)json;


/**
 *  Updates the articles in a seciton with the articles param.
 *
 *  @param articles an array of articles.
 */
- (void)updateWithArticles:(NSArray <ZDKHelpCenterArticleViewModel*>*)articles;

@end
