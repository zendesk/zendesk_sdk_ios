/*
 *
 *  ZDKSupportView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 11/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import "ZDKSpinnerDelegate.h"


/**
 *  The state of a ZDKSupportView
 */
typedef NS_ENUM(NSUInteger, ZDKSupportViewState) {
    /**
     *  Loading content.
     */
    ZDKSupportViewStateContentLoading,
    /**
     *  Content loaded.
     */
    ZDKSupportViewStateContentLoaded,
    /**
     *  Loaded with no content.
     */
    ZDKSupportViewStateEmpty,
    /**
     *  Error loading.
     */
    ZDKSupportViewStateEmptyError,
};


/**
 * A view that displays help center content.
 */
@interface ZDKSupportView : UIView <UIAppearanceContainer>


/**
 *  The state of the support view. 
 */
@property (nonatomic, assign) ZDKSupportViewState viewState;

/**
 * Lists categories, sections and articles.
 */
@property (nonatomic, strong, readonly) UITableView *table;

/**
 * Search field for searching help center content.
 */
@property (nonatomic, strong, readonly) UISearchBar *searchField;

/**
 * Label to be displayed instead of table when search returns no results.
 */
@property (nonatomic, strong, readonly) UILabel *noResultsFoundLabel;

/**
 * Button to contact support, displayed when search returns no results.
 */
@property (nonatomic, strong, readonly) UIButton *noResultsContactButton;


@end
