/*
 *
 *  ZDKSupportView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 11/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
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
@property (nonatomic) ZDKSupportViewState viewState;

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


#pragma mark - Appearance

/**
 * Loading spinner.
 */
@property (nonatomic, strong) id<ZDKSpinnerDelegate> spinner __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Background color for the view.
 */
@property (nonatomic, strong) UIColor *viewBackgroundColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Background color for the table.
 */
@property (nonatomic, strong) UIColor *tableBackgroundColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Searchbar UIBarstyle.
 */
@property (nonatomic, strong) NSNumber *searchBarStyle __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Color of the table separator.
 */
@property (nonatomic, strong) UIColor *separatorColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

#pragma mark noResultsFoundLabel appearance

/**
 * Font to be used for no results found label, shown on no search results.
 */
@property (nonatomic, strong) UIFont *noResultsFoundLabelFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Text color of no results found label, shown on no search results.
 */
@property (nonatomic, strong) UIColor *noResultsFoundLabelColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Background color of no results found label, shown on no search results.
 */
@property (nonatomic, strong) UIColor *noResultsFoundLabelBackground __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

#pragma mark noResultsContactButton appearance

/**
 * Background color of contact support button, shown on no search results.
 */
@property (nonatomic, strong) UIColor *noResultsContactButtonBackground __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Border color of contact support button, shown on no search results.
 */
@property (nonatomic, strong) UIColor *noResultsContactButtonBorderColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Border width of contact support button, shown on no search results.
 */
@property (nonatomic, strong) NSNumber *noResultsContactButtonBorderWidth __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Corner radius of contact support button, shown on no search results.
 */
@property (nonatomic, strong) NSNumber *noResultsContactButtonCornerRadius __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Font of contact support button, shown on no search results.
 */
@property (nonatomic, strong) UIFont *noResultsContactButtonFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * UIEdgeInsets of contact support button, shown on no search results.
 */
@property (nonatomic, strong) NSValue *noResultsContactButtonEdgeInsets __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Title color of contact support button in normal state.
 */
@property (nonatomic, strong) UIColor *noResultsContactButtonTitleColorNormal __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Title color of contact support in highlighted state.
 */
@property (nonatomic, strong) UIColor *noResultsContactButtonTitleColorHighlighted __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 * Title color of contact support in disabled state.
 */
@property (nonatomic, strong) UIColor *noResultsContactButtonTitleColorDisabled __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


#pragma mark Nav bar appearance

/**
 * Add @ annotation when setting, either @NO or @YES.
 */
@property (nonatomic, strong) NSNumber *automaticallyHideNavBarOnLandscape  __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


@end
