//
//  ZDRMASimpleRequestView.h
//  ZDRateMyApp
//
//  Created by Zendesk on 19/02/2014.
//  Copyright (c) 2014 Alan Egan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZDUI.h"
@class ZDRMAConfigObject;


/**
 * Delegate of ZDRMAFeedbackView. The delegate of a ZDRMAFeedbackView object
 * must adopt the ZDRMAFeedbackViewDelegate protocol.
 */
@protocol ZDRMAFeedbackViewDelegate <NSObject>


/**
 * Tells the delegate that the send feedback action has been selected in the
 * feedback dialog. The delegate should handle sending the feedback to an endpoint.
 */
- (void) sendFeedback:(NSString*)feedback;


/**
 * Tells the delegate that the cancel action has been selected in the
 * feedback dialog. The delegate should handle either returning to previous dialog
 * or dissmissing the dialog entirely.
 */
- (void) back;


/**
 * Tells the delegate that the dialog should be closed. The delegate should handle closing 
 * the dialog. 
 *
 */
- (void) closeDialog;


@end


#pragma mark -


typedef NS_ENUM(NSInteger, ZDRMAFeedbackDialogState) {
    ZDRMAFeedbackDialogStateEditing = 0,
    ZDRMAFeedbackDialogStateCancel = 1,
    ZDRMAFeedbackDialogStateSubmitting = 2,
    ZDRMAFeedbackDialogStateSuccess = 3,
    ZDRMAFeedbackDialogStateError = 4
};


/**
 * A ZDRMAFeedbackView contains a header, a text view and a set of buttons.
 */
@interface ZDRMAFeedbackView : UIView <UITextViewDelegate> {
    id<ZDRMAFeedbackViewDelegate> delegate;
}


@property (nonatomic) ZDRMAFeedbackDialogState feedbackState;


/**
 * A ZDRMATextView for text entry.
 */
@property (nonatomic, retain) ZDUITextView *textView;


/**
 * A UIButton calls ZDRMAFeedbackViewDelegate cancel method.
 */
@property (nonatomic, retain) UIButton *backButton;


/**
 * A UIButton calls ZDRMAFeedbackViewDelegate sendFeedback method.
 */
@property (nonatomic, retain) UIButton *submitButton;


/**
 * A UIButton dismisses the ZDRMA dialog.
 */
@property (nonatomic, retain) UIButton *closeButton;


/**
 * A UILabel in the header of the feedback view. This label has only one
 * line and is the main title.
 */
@property (nonatomic, retain) UILabel *titleLabel;


/**
 * A UILabel in the header of the feedback view. This label has three
 * lines and is for any extra details in the header.
 */
@property (nonatomic, retain) UILabel *detailTitleLabel;


/**
 * Displays an image if one has been specified by either successImageName
 */
@property (nonatomic, retain) UIImageView *submissionStatusImageView;


@property (nonatomic, strong) UIColor *buttonColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonSelectedColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *separatorLineColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *headerFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *subheaderFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *textEntryFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *buttonFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) id<ZDSpinnerDelegate> spinner UI_APPEARANCE_SELECTOR;

@property (nonatomic, strong) NSString *successImageName;
@property (nonatomic, strong) NSString *errorImageName;

/**
 * Initializes and returns a ZDRMAFeedbackView with the given ZDRMAFeedbackViewDelegate.
 *
 * This creates a ZDRMAFeedbackView with default values for the tables dimensions and appearance.
 *
 * @param delegate the delegate that implements the ZDRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDRMAFeedbackView.
 *
 */
- (instancetype) initWithDelegate:(id<ZDRMAFeedbackViewDelegate>)del;


/**
 * Displays or hides a spinner over the text view. While the spinner is showing the alpha of the 
 * text view is lowered.
 *
 * @param show If YES the spinner will be shown, if NO the spinner will be hidden.
 */
- (void) showSpinner:(BOOL)show;


/**
 * Transitions the feedback view to a success message state.
 *
 */
- (void) successTransition;


/**
 * Transitions the feedback view to an error message state.
 *
 */
- (void) transitionToError;


/**
 * Transitions the feedback view from an error message state, back to an editing state.
 *
 */
- (void) transitionFromError;


@end

