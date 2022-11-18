//
//  RCLiveVideoDelegate_DP_2_X.h
//  Pods
//
//  Created by 彭蕾 on 2022/11/16.
//

/// 本文件相关接口，只能在 2.x 版本及以下版本可用，之后3.0可能将不起作用
#import <CoreMedia/CMSampleBuffer.h>

#import "RCSProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RCLiveVideoDelegate_DP_2_X <RCSProtocol>

@optional

/// 视频输出回调，可以在此接口做视频流二次开发，例如：美颜。
/// @param sampleBuffer 视频流采样数据
- (nullable CMSampleBufferRef)didOutputSampleBuffer:(nullable CMSampleBufferRef)sampleBuffer DEPRECATED_MSG_ATTRIBUTE("use didOutputFrame: instead");

/// 用户进入房间回调
/// @param userId 用户进入房间
- (void)userDidEnter:(NSString *)userId withUserCount:(NSInteger)count DEPRECATED_MSG_ATTRIBUTE("use onUserUpdateWithJoinUserIds:exitUserIds: in instead");

/// 用户离开房间回调
/// @param userId 用户离开房间
- (void)userDidExit:(NSString *)userId withUserCount:(NSInteger)count DEPRECATED_MSG_ATTRIBUTE("use onUserUpdateWithJoinUserIds:exitUserIds: in instead");

@end

NS_ASSUME_NONNULL_END
