//
//  RCLiveVideoDeprecatedDelegate.h
//  RCLiveVideoLib
//
//  Created by shaoshuai on 2022/9/2.
//

#import <CoreMedia/CMSampleBuffer.h>

#import "RCSProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RCLiveVideoDeprecatedDelegate <RCSProtocol>

@optional

/// 视频输出回调，可以在此接口做视频流二次开发，例如：美颜。
/// @param sampleBuffer 视频流采样数据
- (nullable CMSampleBufferRef)didOutputSampleBuffer:(nullable CMSampleBufferRef)sampleBuffer DEPRECATED_MSG_ATTRIBUTE("use didOutputFrame: instead");

@end

NS_ASSUME_NONNULL_END
