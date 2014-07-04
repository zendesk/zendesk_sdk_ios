//
//  ZDRMATableView.h
//  ZDRateMyApp
//
//  Created by Zendesk on 19/02/2014.
//  Copyright (c) 2014 Alan Egan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZDRMACommon.h"


/**
 * Table header view for ZDRMADialogView.
 */
@interface ZDRMATableHeaderView : UIView


@property (nonatomic, strong) UILabel *textLabel;


- (id) initWithFrame:(CGRect)frame andTitle:(NSString*)title;


@end


#pragma mark -


/**
 * Table cell for ZDRMADialogView. Plain UITableViewCell styled
 * for ZDRMA.
 */
@interface ZDRMADialogViewCell : UITableViewCell


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
 * Delegate of ZDRMADialogView. The delegate of a ZDRMADialogView object
 * must adopt the ZDRMADialogViewDelegate protocol.
 */
@protocol ZDRMADialogViewDelegate <NSObject>


@required

/**
 * Tells the delegate that the rate app action has been selected in the
 * dialog. The delegate handles linking to the app store in this method.
 */
- (void) rateApp;


/**
 * Tells the delegate that the don't ask again action has been selected in the
 * dialog. The delegate handles setting ZDRMADontAskAgain in this method.
 */
- (void) neverShowDialogAgain;

@optional


/**
 * Tells the delegate that the send feedback action has been selected in the
 * dialog. The delegate handles displaying the ZDRMAFeedbackView in this method.
 */
- (void) showFeedbackView;


@end


#pragma mark -


/**
 * A simple table view with limited rows for displaying the options associated with ZDRMA.
 * The table height determins the height of the individual rows and table header. The header and row
 * height is calculated dividing the number of rows plus the header
 */
@interface ZDRMADialogView : UITableView <UITableViewDataSource, UITableViewDelegate> {

    __weak id<ZDRMADialogViewDelegate> delegate;
    ZDRMATableHeaderView *header;
}


/**
 * The rows in the dialog. This should be set with the class method arrayWithZDRMAActions: in
 * ZDRMA. The actions in the array will be displayed in the dialog form top to bottom in the
 * order they were supplied to arrayWithZDRMAActions:.
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
 * Initializes and returns a ZDRMADialogView with the given ZDRMADialogViewDelegate.
 *
 * This creates a ZDRMADialogView with default values for the tables dimensions and appearance.
 *
 * @param delegate the delegate that implements the ZDRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDRMADialogView.
 */
- (id) initWithDelegate:(id<ZDRMADialogViewDelegate>)delegate;


/**
 * Initializes and returns a ZDRMADialogView with the given frame and ZDRMADialogViewDelegate.
 *
 * @param frame A rectangle specifying the initial location and size of the dialog view in
 * its superview's coordinates.
 *
 * @param delegate the delegate that implements the ZDRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDRMADialogView.
 */
- (id) initWithFrame:(CGRect)frame delegate:(id<ZDRMADialogViewDelegate>)delegate;

/**
 * Initializes and returns a ZDRMADialogView with the given frame, style and ZDRMADialogViewDelegate.
 *
 *
 * @param frame A rectangle specifying the initial location and size of the dialog
 * view in its superview's coordinates.
 * @param style A constant that specifies the style of the table view.
 *
 * @param delegate The delegate that implements the ZDRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDRMADialogView.
 */
- (id) initWithFrame:(CGRect)frame
               style:(UITableViewStyle)style
            delegate:(id<ZDRMADialogViewDelegate>)delegate;



@end
