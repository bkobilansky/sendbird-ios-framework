# Change Log

### v3.0.125 (Dec 4, 2018)
* Fixed bug about unread message count subscription.

### v3.0.124 (Dec 3, 2018)
* Fixed bug that can't toggle distinct channel.

### v3.0.123 (Nov 30, 2018)
* Fixed bug that updates unchanged properties of channel or message.

### v3.0.122 (Nov 22, 2018)
* Added `createDistinctChannelIfNotExistWithParams:completionHandler:` method in `SBDGroupChannel`.
   * It creates distinct channel and gets the channel with `isCreated` in `completionHandler` which represents whether the channel is actually created or not.
* Added `getMessageChangeLogsByTimestamp:completionHandler:` method in `SBDBaseChannel`.
   * It retrieves message change logs since the given timestamp.
* Added `hiddenState` type of `SBDGroupChannelHiddenState` property in `SBDGroupChannel` to get channel's hidden state.
   * `SBDGroupChannelHiddenStateUnhidden`: It's not hidden channel.
   * `SBDGroupChannelHiddenStateHiddenAllowAutoUnhide`: It's hidden channel which is automatically unhidden when new message comes in.
   * `SBDGroupChannelHiddenStateHiddenPreventAutoUnhide`: It's hidden channel which is not unhidden when new message comes in.
 * Added `hideChannelWithHidePreviousMessages:allowAutoUnhide:completionHandler:` method to allow automatic unhide on new message in `SBDGroupChannel`.
 * Added `unhideChannelWithCompletionHandler:` method in `SBDGroupChannel` to unhide manually the channel.
 * Added `channelHiddenStateFilter` property type of `SBDChannelHiddenStateFilter` in `SBDGroupChannelListQuery` to filter by `hiddenState`.
   * `SBDChannelHiddenStateFilterUnhiddenOnly`: Get all unhidden channels. (default)
   * `SBDChannelHiddenStateFilterHiddenOnly`: Get all hidden channels which `hiddenState` is `SBDGroupChannelHiddenStateHiddenAllowAutoUnhide` or `SBDGroupChannelHiddenStateHiddenPreventAutoUnhide`.
   * `SBDChannelHiddenStateFilterHiddenAllowAutoUnhide`: Get channels which `hiddenState` is `SBDGroupChannelHiddenStateHiddenAllowAutoUnhide`.
   * `SBDChannelHiddenStateFilterHiddenPreventAutoUnhide`: Get channels which `hiddenState` is `SBDGroupChannelHiddenStateHiddenPreventAutoUnhide`.
  * `SBDGroupChannelParams` conforms `NSCopying`.
  * Minor bug fixed

### v3.0.121 (Nov 15, 2018)
* Changed type of `sender` property in `SBDUserMessage` and `SBDFileMessage` from `SBDUser` to a new class `SBDSender` which extends `SBDUser`.
  * `SBDSender` has `isBlockedByMe` property which indicates that the message sender is blocked by the current user (default: false).
  * `isBlockedByMe` is valid in `SBDGroupChannel` only.
  * Message from blocked users is delivered only when `block_mode` in `Application` is set to `explicit` mode. Otherwise, it's not visible nor delivered.
* Minor bug fixed.

### v3.0.120 (Nov 8, 2018)
* Separated `SBDUserListQuery` into the following query classes according to its specific role.
  * Added `SBDApplicationUserList` as a substitute for `SBDUserListQuery` (Recommended).
  * Added `SBDBlockedUserListQuery`, `SBDBannedUserListQuery`, `SBDMutedUserListQuery`, `SBDParticipantListQuery`.
  * Added properties of `metaDataKeyFilter`, `metaDataValuesFilter`, `userIdsFilter` in `SBDApplicationUserListQuery`.
* Guaranteed the order of sending `SBDFileMessage` regardless of bulk file messages or a single file message.
* Minor bug fixed

### v3.0.119 (Oct 31, 2018)
* Added `SBDScheduledUserMessage` feature to send `SBDUserMessage` at the time specified by a user.
  * Added `SBDScheduledUserMessage` that is a scheduled `SBDUserMessage`.
  * Added `SBDScheduledUserMessageParams` to be delivered as a parameter to register scheduled `SBDUserMessage`.
  * Added `registerScheduledUserMessageWithParams:completionHandler:` in `SBDGroupChannel` to register scheduled `SBDUserMessage`.
* Improved stability.
* Minor bug fixed

### v3.0.118 (Oct 26, 2018)
* Added duration and a description to user mute.
* Added an ordering group channel with meta data value of specific key.
* Minor bug fixed. 

### v3.0.117 (Oct 19, 2018)
* Added a getter `getLastConnectedAt` that returns the current user's latest connection time.

### v3.0.116 (Oct 11, 2018)
* Improved stability.

### v3.0.115 (Sep 21, 2018)
* Added a method `getReadStatusIncludingAllMembers:` that gets readStatus in the group channel.
* Added a method `getReadMembersWithMessage:includeAllMembers:` that returns a list of members who read the message in the group channel.   
* Added a method `getUnreadMembersWithMessage:includeAllMembers:` that returns a list of members who did not read the message in the group channel.  
* Enabled to use `isEqual:` in Channel classes (`SBDBaseChannel`, `SBDGroupChannel`, `SBDOpenChannel`), Message classes (`SBDBaseMessage`, `SBDUserMessage`, `SBDFileMessage`, `SBDAdminMessage`), User classes (`SBDUser`, `SBDMember`) to compare deep-equality with other instance.
* Fixed connection method (ex. `connectWithUserId:accessToken:completionHandler:`) so that can receive call-back with an error when `disconnectWithCompletionHandler:` was called while connecting to SendBird.
* Changed setters of filter in query class (`SBDGroupChannelListQuery`, `SBDGroupChannelMemberListQuery`, `SBDOpenChannelListQuery`, `SBDPreviousMessageListQuery`, `SBDPublicGroupChannelListQuery`, `SBDUserListQuery`) into properties.
* Minor bug fixed.  
* Deprecated some feature.  
  * Deprecated method `getReadMembersWithMessage:` in `SBDGroupChannel`.  
  * Deprecated method `getUnreadMembersWithMessage:` in `SBDGroupChannel`.  
  * Deprecated method `getReadStatus` in `SBDGroupChannel`.  
  * Deprecated enum `SBDWebSocketClosing` in `SBDWebSocketConnectionState`.

### v3.0.114 (Sep 14, 2018)
* Minor bug fixed.  

### v3.0.112 (Sep 10, 2018)
* From now, `useMemberAsMessageSender` option is YES by default.
* Fixed a bug previous messages not showing the senders' latest user metadata.

### v3.0.111 (Sep 5, 2018)
* Minor bug fixed.

### v3.0.110 (Aug 24, 2018)
* Added `updateUserMessageWithMessageId:userMessageParams:completionHandler:` with `SBDUserMessageParams` in `SBDBaseChannel`.
* Added `updateFileMessageWithMessageId:fileMessageParams:completionHandler:` with `SBDFileMessageParams` in `SBDBaseChannel`.
* Minor bug fixed.

### v3.0.109 (Aug 16, 2018)
 * Improved connection management.

### v3.0.107 (Aug 3, 2018)
 * Added `invitedAt` in `SBDGroupChannel`.

### v3.0.106 (Jul 13, 2018)
 * Added `loadWithCompletionHandler:`, `setMessageTypeFilter:`, `setCustomTypeFilter:`, `setSenderUserIdsFilter:` in `SBDPreviousMessageListQuery`.
 * Added `getNextMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getPreviousMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getPreviousAndNextMessagesByTimestamp:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getNextMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getPreviousMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, and `getPreviousAndNextMessagesByMessageId:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:completionHandler:` in `SBDBaseChannel`.

### v3.0.105 (Jul 6, 2018)
 * Disabled to put the current user into `mentionedUsers`, `mentionedUserIds` in `SBDUserMessageParams` and `SBDFileMessageParams`.
 * Changed not to increase `unreadMentionCount` and not to call `channel:didReceiveMention:` for CHANNEL mention by the current user  (i.e. the message sender is the current user).

### v3.0.104 (Jun 29, 2018)
* Added `unreadMentionCount` property in `SBDGroupChannel`.
* Added enum `SBDCountPreferenceUnreadMentionCountOnly` in `SBDCountPreference`.
* Added `SBDUnreadItemKeyNonSuperUnreadMentionCount`, `SBDUnreadItemKeySuperUnreadMentionCount`, SBDUnreadItemKeyGroupChannelUnreadMessageCount`, `SBDUnreadItemKeyGroupChannelUnreadMentionCount`, `SBDUnreadItemKeyGroupChannelInvitationCount` in `SBDUnreadItemKey`.
* Added mention type.
  * New enum type `SBDMentionType` that has `SBDMentionTypeUsers` and `SBDMentionTypeChannel`.
  * New property in `SBDBaseMessage`. 
* Deprecated instance method, `getUnreadItemCountWithKey:completionHandler:` in `SBDGroupChannel`.
  * Replaced with class method `getUnreadItemCountWithKey:completionHandler:` in `SBDGroupChannel` instead.
* Minor bug fixed.

### v3.0.102 (Jun 22, 2018)
 * Added `nicknameStartsWithFilter` in `SBDGroupChannelMemberListQuery`.
 * Added enum `SBDCountPreference`.
   * Enum has `SBDCountPreferenceAll`, `SBDCountPreferenceUnreadMessageCountOnly`, `SBDCountPreferenceOff`.
   * Added `myCountPreference` in `SBDGroupChannel` as a getter.
   * Added `setMyCountPreference:completionHandler:` in `SBDGroupChannel` as an aynchronous setter.
 * Fixed a bug that `myRole` is not updated in `SBDGroupChannel`.

### v3.0.101 (Jun 13, 2018)
 * Added `joinedMemberCount` to get count of member joined in `SBDGroupChannel`.
 * Added `myMutedState` to show whether the current user is muted or not in `SBDGroupChannel`.
 * Added an api of `getUnreadItemCountWithKey:completionHandler:` in `SBDGroupChannel`.
   * The api gets an instance of `SBDUnreadItemCount` that contains properties of `nonSuperUnreadMessageCount`, `superUnreadMessageCount`, `nonSuperInvitationCount`, `superInvitationCount`.
   * As a parameter, bitmask `SBDUnreadItemKey` is used. It has `SBDUnreadItemKeyNonSuperUnreadMessageCount`, `SBDUnreadItemKeySuperUnreadMessageCount`, `SBDUnreadItemKeyNonSuperInvitationCount`, `SBDUnreadItemKeySuperInvitationCount`.
 
### v3.0.100 (Jun 1, 2018)
 * Added a setter for typing indicator throttling interval.
 * Fixed a minor bug for `buildFromSerialize:`
 * Fixed a minor bug when uploading file in background.
 
### v3.0.99 (May 23, 2018)
 * Fixed a minor bug when uploading file in background.

### v3.0.98 (May 17, 2018)
 * Fixed an occasional member count mismatch in a super group channel.

### v3.0.97 (May 15, 2018)
 * Added a property named `myRole` in the `SBDGroupChannel` which is a role of current user in the group channel.
 * Added `SBDGroupChannelTotalUnreadMessageCountParams` class that is used to get total unread message count.

### v3.0.96 (May 3, 2018)
 * Ordered member list by nickname alphabetically.
 * Fixed a bug that an encrypted file url contains duplicated query keys.
 * Fixed minor bug.

### v3.0.95 (Apr 23, 2018)
 * Fixed minor bug.

### v3.0.94 (Apr 20, 2018)
 * Deprecated `SBDGroupChannelOperatorFilter` in `SBDGroupChannelMemberListQuery`.
 * Added `createOperatorListQuery` in `SBDBaseChannel` to query users who are operators in the channel.
 * Removed internal methods.
 * Changed code convention in headers.
 * Updated project build setting.
 * Minor bug fix.  

### v3.0.93 (Mar 30, 2018)
 * Added `SBDPushNotificationDeliveryOption` to determine how to deliver the push notification when sending a user or a file message.
 * Added a method that gets a unread message count with custom types of group channel.

### v3.0.92 (Mar 21, 2018)
 * Changed an ephemeral `SBDGroupChannel` to maintain fields of `lastMessage` and `unreadMessageCount` after connected.

### v3.0.91 (Mar 20, 2018)
 * Fixed a bug that can't send file message with a binary file.

### v3.0.90 (Mar 7, 2018)
 * Added **mentioning to specific user**.
   * added channel delegate, `channel:didReceiveMention:`, which is called when the current user is mentioned.
   * added a property named `mentionedUsers` which means the users received mention together. 
 * Added **ephemeral group channel**.
   * added a property named `isEphemeral` in `SBDBaseChannel`.
   * added a property named `isEphemeral` in `SBDGroupChannelParams`.
 * Added api that can **message with an instance of MessageParams** .
   * added `SBDUserMessageParams`, `SBDFileMessageParams` based on `SBDBaseMessageParams` to message.
   * added an api, `sendUserMessageWithParams:completionHandler:`, used to send user message with message params.
   * added apis, `sendFileMessageWithParams:completionHandler:` and `sendFileMessageWithParams:progressHandler:completionHandler:`, used to send file message with message params.
 * Added **member's state** in group channel.
   * added a property named `myMemberState` type of `SBDMemberState` which means state of member in `SBDGroupChannel`.
   * added `SBDMemberStateNone` type of enum SBDMemberState.
 * Added `setConnectionTimeout:` to configure websocket timeout.
 * Removed `SBDChannelEvent.h` and `SBDCommand.h`.

### v3.0.89 (Feb 22, 2018)
 * **Changed channel 6 delegates parameter type from `SBDOpenChannel` to `SBDBaseChannel`** 
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasMuted: (SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasMuted:(SBDUser * _Nonnull)user`
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasUnmuted:(SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasUnmuted:(SBDUser * _Nonnull)user`
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasBanned:(SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasBanned:(SBDUser * _Nonnull)user`
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasUnbanned:(SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasUnbanned:(SBDUser * _Nonnull)user`
   * changed from `channelWasFrozen:(SBDOpenChannel * _Nonnull)sender` to `channelWasFrozen:(SBDBaseChannel * _Nonnull)sender`
   * changed from `channelWasUnfrozen:(SBDOpenChannel * _Nonnull)sender` to `channelWasUnfrozen:(SBDBaseChannel * _Nonnull)sender`
 * Moved property named `isFrozen` from **SBDOpenChannel** to **SBDBaseChannel**
 * Fixed error enum type.
 * Removed warning signals.

### v3.0.88 (Feb 6, 2018)
 * Added `setSharedContainerIdentifier:` in `SBDMain` to set shared container identifier of background session configuration for App Extension
 * Added **PublicGroupChannel** features.
   * new **SBDPublicGroupChannelListQuery** class.
   * added `isPublic` in **SBDGroupChannel** to flag public group channel or private group channel. 
   * added `createPublicGroupChannelListQuery` in **SBDGroupChannel** to create public group channel list query.
   * added `joinWithCompletionHandler:` in **SBDGroupChannel** to join public group channel.
   * added filters `publicChannelFilter`, `customTypeStartsWithFilter` in **SBDPublicGroupChannelListQuery**.
   * added enum `SBDGroupChannelPublicChannelFilter` - `SBDGroupChannelPublicChannelFilterAll`, `SBDGroupChannelPublicChannelFilterPublic`, `SBDGroupChannelPublicChannelFilterPrivate`.
   * added enum `SBDPublicGroupChannelMembershipFilter` - `SBDPublicGroupChannelMembershipFilterAll`, `SBDPublicGroupChannelMembershipFilterJoined`.
 * Added `channelUrl` in **SBDGroupChannelParams** to create group channel with explicit channel url.
 * Added `SBDGroupChannelListOrderChannelNameAlphabetical` in `SBDGroupChannelListOrder` enum.
 * Added enum `SBDPublicGroupChannelListOrder` - `SBDPublicGroupChannelListOrderChronological`, `SBDPublicGroupChannelListOrderChannelNameAlphabetical`.
 * Removed `SBDLogLevelDebug` in log level.
 * Improved socket connection.

### v3.0.87 (Feb 5, 2018)
 * Added `setSharedContainerIdentifier:` in `SBDMain` to set shared container identifier of background session configuration for App Extension

### v3.0.86 (Jan 29, 2018)
 * Fixed **SBDGroupChannel** instance method name `getUnreadMemebersWithMessage:` to `getUnreadMembersWithMessage:`.
 * Fixed nullability of `init` in **SBDFriendListQuery**.
 * Deprecated **SBDGroupChannel** instance methods - `getLastSeenAtByUser:`, `getLastSeenAtByUserId:`.
 * Added **SBDGroupChannelParams** to create or update group channel.
   * added `createChannelWithParams:completionHandler:` in **SBDGroupChannel** to create group channel with params.
   * added `updateChannelWithParams:completionHandler:` in **SBDGroupChannel** to update group channel with params.
 * Added **SBDGroupChannelMemberListQuery** to query member list in group channel.
   * added `createMemberListQuery` in **SBDGroupChannel** to create member list query instance.
 * Added **SuperGroupChannel** features.
   * added `isSuper` in **SBDGroupChannel** to flag super group channel or not.
   * added enum `SBDGroupChannelSuperChannelFilter` - `SBDGroupChannelSuperChannelFilterAll`, `SBDGroupChannelSuperChannelFilterSuper`, `SBDGroupChannelSuperChannelFilterNonSuper`.
   * added `superChannelFilter` in **SBDGroupChannelListQuery** to filter super group channel.
 * Removed `coverImageName` in **SBDGroupChannelParams** 
 
### v3.0.85 (Jan 20, 2018)
 * Improved file upload.

### v3.0.84 (Jan 17, 2018)
 * Fixed a bug of updating channel.

### v3.0.83 (Jan 16, 2018)
 * Added dirty flag for cache in **SBDGroupChannel**, **SBDOpenChannel**.

### v3.0.82 (Jan 11, 2018)
 * Moved `markAsReadAllWithCompletionHandler:` from **SBDGroupChannel** to **SBDMain**.
 * Added `markAsReadWithChannelUrls:completionHandler:` in **SBDMain** to mark ad read some channels.
 * Added member state filter enum - `SBDMemberStateFilterInvitedByFriend`, `SBDMemberStatefilterInvitedByNonFriend`.
 * Changed notification key in **SBDReachability** not to conflict duplicate.
 * Changed callback parameters of `getFriendChangeLogsByToken:completionHandler:`. Combined `addedUsers` and `updatedUsers` to `updatedUsers`.
 * Change unread message count behavior.
 * Updated SocketRocket library.
 * Fixed SocketRocket library not working with 'MyDataManager' application.
 * Improved routing.
 
### v3.0.81 (Jan 10, 2018)
 * Improved socket connection.

### v3.0.80 (Jan 5, 2018)
 * Added `setCustomTypesFilter` in `SBDGroupChannelListQuery` to search group channels.  
 * Added `originalProfileUrl` in `SBDUser` for getting original profile image.  
 * Added **Friend** feature.
   * `addFriendsWithUserIds:completionHandler:` adds friends with friends' user IDs. 
   * `deleteFriendWithUserId:completionHandler:` deletes a friend with a friend's user ID.
   * `deleteFriendsWithUserIds:completionHandler:` deletes friends with friends' user IDs.  
   * `deleteFriendWithDiscovery:completionHandler:` deletes friend's discovery key.
   * `deleteFriendsWithDiscoveries:completionHandler:` deletes friends' discovery keys. 
   * `uploadFriendDiscoveries:completionHandler:` adds friend using discovery key. 
   * `getFriendChangeLogsByToken:completionHandler:` gets the logs about changing friend relation. 
   * `createFriendListQuery` creates a `SBDFriendListQuery` object for getting friend list. 
   * `addUserEventDelegate:identifier:` adds delegate for receiving user event. 
   * `removeUserEventDelegateForIdentifier:` removes user event delegate with identifier.
   * `removeAllUserEventDelegates` removes all user event delegate.
   * `SBDUserEventDelegate`: user event delegate. 
 * From now, even when you call `connectWithUserId:...` before the previous `connectWithUserId:...` finishes, all of them get called back for the connection establishment result at the same time. 

### v3.0.79 (Dec 19, 2017)
* Fixed file uploading bug.

### v3.0.78 (Dec 14, 2017)
* Fixed connection bug.

### v3.0.77 (Dec 8, 2017)
* Fixed `state` of `SBDMember` bug.

### v3.0.75 (Dec 8, 2017)
* Added `isActive` property to `SBDUser`.

### v3.0.74 (Nov 29, 2017)
* Fixed bug.

### v3.0.73 (Nov 13, 2017)
* Added `channelWasHidden:` delegate to `SBDChannelDelegate` for a channel hidden event.

### v3.0.72 (Nov 12, 2017)
* Added a group channel hidden event.

### v3.0.71 (Nov 7, 2017)
* Added `isHidden` property to a group channel.

### v3.0.70 (Oct 24, 2017)
* Fixed bug of file message's custom type.

### v3.0.69 (Oct 18, 2017)
* Turned off LLVM profiling and code coverage options.

### v3.0.68 (Oct 11, 2017)
* Bitcode support.

### v3.0.67 (Oct 6, 2017)
* **DO NOT USE THIS VERSION**
* Fixed reconnection bug.

### v3.0.66 (Sep 7, 2017)
* Fixed message parsing bug.

### v3.0.65 (Aug 28, 2017)
* Added a method to count my group channels.
* Added a method to reset the group channel history.

### v3.0.64 (Aug 21, 2017)
* Added user block flags to a member of group channels.
* Added a method to get message changelogs.
* Deprecated filters of channel list query as properties.
* Added methods for filters of channel list query.

### v3.0.63 (Aug 18, 2017)
* Added new option to the method to hide a group channel for hiding the previous messages when the channel was hidden.
* Added freeze state to open channel.
* Added user meta data.
* Added meta data filter to user list query.

### v3.0.62 (Aug 11, 2017)
* Set default value to channel data.
* Added conditions to avoid null value when channel instance is updated.
* Fixed URL encoding bug.
* Fixed memory leak.
* Added events for changing meta counters and meta data.

### v3.0.61 (Jul 25, 2017)
* Added channel url filter for group channel list query.

### v3.0.60 (Jul 19, 2017)
* Fixed serialization bug.

### v3.0.59 (Jul 17, 2017)
* Fixed serialization bug.

### v3.0.58 (Jul 15, 2017)
* Added methods to copy a user message and a file message to another channel.

### v3.0.57 (Jul 10, 2017)
* Added `SBDMember` class for an invitation.
* Changed member objects of `SBDGroupChannel` to `SBDMember` objects.
* Added the methods to accept and decline an invitation to `SBDGroupChannel` object.
* Added `SBDMemberStateFilter` for group channel list query.
* Added the methods to set and get the channel invitation preference for automatic acceptance.
* Added `channel:userDidJoin:inviter:` delegate for invitation acceptance.
* Added `channel:didReceiveInvitation:inviter:` delegate for an invitation.

### v3.0.56 (Jul 4, 2017)
* Added a setter and a getter for push sound.

### v3.0.55 (Jun 14, 2017)
* Added custom type filter to channel query.

### v3.0.54 (Jun 5, 2017)
* Fixed bug of participant count in open channel.
* Added a channel URL parameter to a method to create an open channel.

### v3.0.53 (May 19, 2017)
* Added methods to update a user message and a file message.
* Added a delegate to receive the event for message updating.
* Added a method to cancel uploading file message.

### v3.0.52 (Apr 24, 2017)
* Improved connection performance.

### v3.0.51 (Apr 19, 2017)
* **Only iOS 8.0 or later is supported from this version.** `Podfile` has to be updated for dynamic frameworks like this:
```
platform :ios, '8.0'
use_frameworks!

target YOUR_PROJECT_TARGET do
  pod 'SendBirdSDK'
end
```

### v3.0.50 (Apr 14, 2017)
* This is the biggest release since our initial v3 release. Some of changes should be carefully taken when you update the SDK.

* Now every completion handler/delegates in SDK is returned to **MAIN THREAD queue**.  It used to be inconsistent so some were returned to main thread and others to background thread.  **Be aware that you shouldn't call any blocking/long running job without using custom background queue in our completion handler/delegates!!!!**

For your convenience we added the methods to set default dispatch queue for every delegates and completion handlers. The queue can be changed like this:

```swift
[SBDMain setCompletionHandlerDelegateQueue:dispatch_get_main_queue()];
```
or
```swift
[SBDMain setCompletionHandlerDelegateQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)];
```

* The auto reconnection is also triggered with network awareness. The default option is on but you might want to turn it off if you have manual network detection to call reconnect(). It can be turned on or off like this:
```swift
[SBDMain setNetworkAwarenessReconnection:YES];
```
or
```swift
[SBDMain setNetworkAwarenessReconnection:NO];
```
* Now we support file uploading in background so you can send very large files.

### v3.0.45 (Apr 8, 2017)
* Improved connection speed.

### v3.0.44 (Mar 13, 2017)
* Fixed serialization bug.

### v3.0.43 (Mar 9, 2017)
* Fixed unread message count bug.

### v3.0.42 (Mar 8, 2017)
* Fixed unread message count sync problem.
* Added a method to get total unread channel count.

### v3.0.41 (Mar 6, 2017)
* Added option for sync member in group channel and sender of message.
* Added accurate error.
* Fixed unread count bug of group channel.
* Added message type and custom type options for getting messages.

### v3.0.40 (Mar 2, 2017)
* Added serialization for SBDUser, SBDBaseChannel, and SBDBaseMessage object.

### v3.0.39 (Feb 25, 2017)
* Fixed bugs of send user message and file message.

### v3.0.38 (Feb 17, 2017)
* Added file encryption.
* Fixed connection bug.

### v3.0.37 (Feb 14, 2017)
* Fixed bug of updating meta counter of channel.

*Note that we don't return result objects anymore when there's an error in completion handlers starting from this version. Please make sure that you don't use a result object when an error occurs after updating SDK.*

### v3.0.36 (Jan 31, 2017)
* Fixed bug of thumbnail image in file message.

### v3.0.35 (Jan 30, 2017)
* Added a method to run reconnection.
* Improved unread message count management.
* Added error for uninitialized class.

### v3.0.33 (Jan 28, 2017)
* Improved usability of channel delegates and connection delegates.

### v3.0.32 (Jan 20, 2017)
* Modified network error code.

### v3.0.31 (Jan 19, 2017)
* Added error code for network error.

### v3.0.30 (Jan 18, 2017)
* More accurate connection state.

### v3.0.29 (Jan 17, 2017)
* Fixed the bug of unread message count in group channel.
* Added file name parameter to the message for sending file with URL.

### v3.0.28 (Jan 9, 2017)
* Added file path parameter to the methods which are for uploading file.

### v3.0.27 (Jan 4, 2017)
* Added the class to represent a thumbnail max size.

### v3.0.26 (Jan 3, 2017)
* Fixed the bug of the group channel's data.
* Added the feature for generating the thumbnail of the image file message.

### v3.0.25 (Dec 23, 2016)
* Added a feature that sets a push notification template.

### v3.0.24 (Dec 19, 2016)
* Fixed channel URL and user ID encoding bug.
* Fixed bug of creating group channel with distinct option.

### v3.0.22 (Dec 16, 2016)
* Added `unique` option to push registration.

### v3.0.21 (Dec 6, 2016)
* Fixed bug of unread message count of group channel.
* Added `isPushEnabled` property to `SBDGroupChannel` in order to represent the push notification configuration.
* Deprecated `getPushPreferenceWithCompletionHandler:` of `SBDGroupChannel`. 

### v3.0.20 (Dec 2, 2016)
* Fixed bug of unread message count and last message of group channel.

### v3.0.19 (Dec 1, 2016)
* Added user IDs filters and query type to `SBDGroupChannelListQuery`.
* Added channel custom type for `SBDOpenChannel` and `SBDGroupChannel`.
* Fixed to call `channelWasChanged:` delegate when unread message count or last message has been updated.
* Fixed bug of reconnection for `SBDOpenChannel`.

### v3.0.18 (Nov 23, 2016)
* Fixed bug of last message of group channels.

### v3.0.17 (Nov 4, 2016)
* Fixed connection bug.

### v3.0.16 (Nov 3, 2016)
* Added group channel list search by a member nickname. (Search by multiple nicknames option in v3.0.15 is no more supported.)
* Added auto-translating feature to SBDUserMessage.
* Improved connection performance.

### v3.0.15 (Oct 31, 2016)
* Added custom type to messages.
* Added group channel list search by member nicknames and user IDs.
* Added creating and updating channel cover image with binary file.

### v3.0.14 (Oct 11, 2016)
* Fixed URL encoding bug.
* Fixed minor bug.

### v3.0.13 (Oct 4, 2016)
* Support Base SDK 9.3
* Fixed bug of the channel type of messages.

### v3.0.12 (Sep 30, 2016)
* Support Carthage.
* Fixed unread message count bug.
* Fixed minor bugs.

### v3.0.11 (Sep 23, 2016)
* Fixed bug of disconnection and reconnection (APNS-related bug).

### v3.0.10 (Sep 13, 2016)
* Removed validation of sending a user message.
* Added a channel type to messages from a message query.

### v3.0.9 (Sep 6, 2016)
* Fixed bug of `data` of `SBDFileMessage`.
* Added a method to get user list with user IDs(`+ createUserListQueryWithUserIds:` of `SBDMain`).
* Added a method to register a APNS device token without login(`+ registerDevicePushToken:completionHandler:` of `SBDMain`).
* Added keywords for open channel name and URL search(`urlKeyword` and `nameKeyword` of `SBDOpenChannelListQuery`).
* Added a method to get a total unread message count(`+ getTotalUnreadMessageCountWithCompletionHandler:` of `SBDGroupChannel`).
* Added a method to get a last timestamp when a user read at the channel(`- getLastSeenAtByUser:` and `- getLastSeenAtByUserId:` of `SBDGroupChannel`).
* Added a method to get members who read the message(`- getReadMembersWithMessage:` of `SBDGroupChannel`).
* Added a method to get members who did not read the message(`- getUnreadMemebersWithMessage:` of `SBDGroupChannel`).
* Added a method to get the read status(`- getReadStatus` of `SBDGroupChannel`).
* Added methods to set push preference(`- setPushPreferenceWithPushOn:completionHandler:` and `- getPushPreferenceWithCompletionHandler:` of `SBDGroupChannel`. `+ setDoNotDisturbWithEnable:startHour:startMin:endHour:endMin:timezone:completionHandler:` and `+ getDoNotDisturbWithCompletionHandler:` of `SBDMain`).
* Deprecated `+ registerPushToken:completionHandler:` of `SBDMain`.

### v3.0.8 (Sep 1, 2016)
* Fixed group channel unread count bug.

### v3.0.7 (Sep 1, 2016)
* Fixed minor bug.

### v3.0.6 (Sep 1, 2016)
* Added URL encoding to API parameters.

### v3.0.5 (Sep 1, 2016)
* ** DO NOT USE THIS VERSION **

### v3.0.4 (Aug 30, 2016)
* Removed duplicated symbols.

### v3.0.3 (Aug 30, 2016)
* Removed duplicated symbol.

### v3.0.2 (Aug 26, 2016)
* Updated version.

### v3.0.1 (Aug 25, 2016)
* Fixed reconnection bug.

### v3.0.0 (Aug 12, 2016)
* First release.

