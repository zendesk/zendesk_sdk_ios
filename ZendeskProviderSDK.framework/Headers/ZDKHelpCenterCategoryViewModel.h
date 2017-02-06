/*
 *
 *  ZDKHelpCenterCategoryViewModel.h
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

@class ZDKHelpCenterSectionViewModel;

@interface ZDKHelpCenterCategoryViewModel : NSObject <ZDKHelpCenterViewModel>

/**
 *  Category id.
 *
 *  @since 1.7.0.1
 */
@property (nonatomic, copy) NSString *categoryId;

/**
 *  Category Name.
 *
 *  @since 1.7.0.1
 */
@property (nonatomic, copy) NSString *name;

/**
 *  An array of sections that are contained within the category.
 *
 */
@property (nonatomic, copy) NSArray<ZDKHelpCenterSectionViewModel *> *sections;

/**
 *  Parses returned json to categories
 *
 *  @param json The Json passed into it
 *
 *  @return An array of help center categories
 */
+ (NSArray<ZDKHelpCenterCategoryViewModel *> *)parseCategories:(NSDictionary *)json;

/**
 *  Parses Json in a single category
 *
 *  @param json The Json passed in
 *
 *  @return a single category
 *
 */
+ (ZDKHelpCenterCategoryViewModel *)parseCategory:(NSDictionary *)json;

- (void)updateWithSection:(ZDKHelpCenterSectionViewModel*)section;

@end
