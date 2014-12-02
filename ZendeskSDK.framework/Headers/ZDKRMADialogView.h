/*
 *
 *  ZDKRMADialogView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/02/2014.  
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
#import "ZendeskSDKConstants.h"


/**
 * Table header view for ZDKRMADialogView.
 */
@interface ZDKRMATableHeaderView : UIView


@property (nonatomic, strong) UILabel *textLabel;


- (id) initWithFrame:(CGRect)frame andTitle:(NSString*)title;


@end


#pragma mark -


/**
 * Table cell for ZDKRMADialogView. Plain UITableViewCell styled
 * for ZDKRMA.
 */
@interface ZDKRMADialogViewCell : UITableViewCell


@property (nonatomic, strong) UIColor *bgColor;
@property (nonatomic, strong) UIColor *selectedBgColor;


- (instancetype) initWithStyle:(UITableViewCellStyle)style
               reuseIdentifier:(NSString*)reuseIdentifier
                separatorColor:(UIColor*)theSeparatorColor
               backgroundColor:(UIColor*)theBgColor
       selectedBackgroundColor:(UIColor*)theSelectedBgColor;


@end


#pragma mark -


/**
 * Delegate of ZDKRMADialogView. The delegate of a ZDKRMADialogView object
 * must adopt the ZDKRMADialogViewDelegate protocol.
 */
@protocol ZDKRMADialogViewDelegate <NSObject>


@required

/**
 * Tells the delegate that the rate app action has been selected in the
 * dialog. The delegate handles linking to the app store in this method.
 */
- (void) rateApp;


/**
 * Tells the delegate that the don't ask again action has been selected in the
 * dialog. The delegate handles setting ZDKRMADontAskAgain in this method.
 */
- (void) neverShowDialogAgain;

@optional


/**
 * Tells the delegate that the send feedback action has been selected in the
 * dialog. The delegate handles displaying the ZDKRMAFeedbackView in this method.
 */
- (void) showFeedbackView;


@end


#pragma mark -


/**
 * A simple table view with limited rows for displaying the options associated with ZDKRMA.
 * The table height determins the height of the individual rows and table header. The header and row
 * height is calculated dividing the number of rows plus the header
 */
@interface ZDKRMADialogView : UITableView <UITableViewDataSource, UITableViewDelegate> {

    __weak id<ZDKRMADialogViewDelegate> delegate;
    ZDKRMATableHeaderView *header;
}


/**
 * The rows in the dialog. This should be set with the class method arrayWithZDKRMAActions: in
 * ZDKRMA. The actions in the array will be displayed in the dialog form top to bottom in the
 * order they were supplied to arrayWithZDKRMAActions:.
 */
@property (nonatomic, retain) NSArray *rows;


@property (nonatomic, strong) UIColor *headerBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *headerColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *separatorLineColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonSelectedBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *headerFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *buttonFont UI_APPEARANCE_SELECTOR;


/**
 * Initializes and returns a ZDKRMADialogView with the given ZDKRMADialogViewDelegate.
 *
 * This creates a ZDKRMADialogView with default values for the tables dimensions and appearance.
 *
 * @param delegate the delegate that implements the ZDKRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDKRMADialogView.
 */
- (id) initWithDelegate:(id<ZDKRMADialogViewDelegate>)delegate;


/**
 * Initializes and returns a ZDKRMADialogView with the given frame and ZDKRMADialogViewDelegate.
 *
 * @param frame A rectangle specifying the initial location and size of the dialog view in
 * its superview's coordinates.
 *
 * @param delegate the delegate that implements the ZDKRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDKRMADialogView.
 */
- (id) initWithFrame:(CGRect)frame delegate:(id<ZDKRMADialogViewDelegate>)delegate;

/**
 * Initializes and returns a ZDKRMADialogView with the given frame, style and ZDKRMADialogViewDelegate.
 *
 *
 * @param frame A rectangle specifying the initial location and size of the dialog
 * view in its superview's coordinates.
 * @param style A constant that specifies the style of the table view.
 *
 * @param delegate The delegate that implements the ZDKRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDKRMADialogView.
 */
- (id) initWithFrame:(CGRect)frame
               style:(UITableViewStyle)style
            delegate:(id<ZDKRMADialogViewDelegate>)delegate;



@end
