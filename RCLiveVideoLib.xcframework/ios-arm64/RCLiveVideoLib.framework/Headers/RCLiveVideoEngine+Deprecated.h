//
//  RCLiveVideoEngine+Deprecated.h
//  RCLiveVideoLib
//
//  Created by shaoshuai on 2022/9/2.
//

#import "RCLiveVideoEngine.h"

NS_ASSUME_NONNULL_BEGIN

@interface RCLiveVideoEngine (Deprecated)

/// 观众加入房间，订阅CDN流
/// 如果videoSizePreset或fps大于视频流的最大值，则使用最大值
/// @param roomId 房间id
/// @param videoSizePreset 视频大小
/// @param FPS 视频帧率
/// @param completion 结果回调
/// 注意：如果使用该接口，请提客户工单，进行后台配置
- (void)joinCDNRoom:(nonnull NSString *)roomId
    videoSizePreset:(RCRTCVideoSizePreset)videoSizePreset
                FPS:(RCRTCVideoFPS)FPS
         completion:(nonnull RCLVResult)completion DEPRECATED_MSG_ATTRIBUTE("use setCDNDataSource instead");

/// 结束直播
/// @param completion 结果回调
- (void)finish:(nonnull RCLVResult)completion DEPRECATED_MSG_ATTRIBUTE("use leaveRoom: API instead");

@end

NS_ASSUME_NONNULL_END
