//
//  SBDGroupChannelChangeLogsParams.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/20/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// An object that represents the parameters for the The method returns channels according to the properties in this object.
/// @note This class is available 3.0.182
@interface SBDGroupChannelChangeLogsParams : NSObject

/// Determines whether to include the empty channels in the results.
/// @note The default value is `YES`.
/// @since 3.0.182
@property (nonatomic) NSArray<NSString *> *customTypes;

/// Determines whether to include the empty channels in the results.
/// @note The default value is `YES`.
/// @since 3.0.182
@property (atomic) BOOL includeEmptyChannel;

/// Determines whether to include the frozen channels in the results.
/// @note The default value is `YES`.
/// @since 3.0.182
@property (atomic) BOOL includeFrozenChannel;

@end

NS_ASSUME_NONNULL_END
