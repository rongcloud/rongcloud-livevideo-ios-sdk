//
//  RCLiveVideoEngine.h
//  RCE
//
//  Created by 叶孤城 on 2021/9/2.
//

#import <RongRTCLib/RongRTCLib.h>

#import "RCLiveVideoErrorCode.h"
#import "RCLiveVideoDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^RCLVResultBlock)(RCLiveVideoErrorCode code);

@protocol RCLiveVideoDelegate;
@interface RCLiveVideoEngine : NSObject

@property (nonatomic, readonly) NSString *roomId;
@property (nonatomic, readonly) RCRTCLiveRoleType currentRole;
@property (nonatomic, readonly) NSArray<NSString *> *liveVideoUserIds;

@property (nonatomic, weak) id<RCLiveVideoDelegate> delegate;

+ (instancetype)shared;

@end

/// 房主
@interface RCLiveVideoEngine (host)

/// 房主准备直播，视频流回调
- (void)prepare;

/// 开始直播
/// @param roomId 房间id
/// @param completion 结果回调
- (void)begin:(NSString *)roomId completion:(RCLVResultBlock)completion;

/// 结束直播并离开房间
/// 注意：
/// SDK 不具备关闭房间能力，请通过服务器接口关闭房间。请在关闭房间之前调用本方法。
/// @param completion 结果回调
- (void)finish:(RCLVResultBlock)completion;

@end

/// 观众
@interface RCLiveVideoEngine (audience)

/// 加入房间，如果没有则创建
/// @param roomId 房间id
/// @param completion 结果回调
- (void)joinRoom:(nonnull NSString *)roomId completion:(nullable RCLVResultBlock)completion;

/// 离开房间
/// @param completion 结果回调
- (void)leaveRoom:(nullable RCLVResultBlock)completion;

@end

@interface RCLiveVideoEngine (operation)

/// 请求视频直播，根据时间先后最多有10人等待
/// @param index 观众期望加入的位置。
/// 注意：
/// 麦位总数由连麦类型决定，比如：一对一场景，麦位数量为1；九宫格，麦位数量为9。
/// 如果，麦位传入为-1，那么，用户上麦时，SDK 会自动查询第一个空麦位。
/// @param completion 结果回调
- (void)requestLiveVideo:(NSInteger)index completion:(nonnull RCLVResultBlock)completion;

/// 取消上麦请求
/// @param completion 结果回调
- (void)cancelRequest:(nullable RCLVResultBlock)completion;

/// 接受上麦请求
/// 如果上麦的麦位已被占用，SDK 会自动查询第一个空麦位。
/// @param userId 目标用户id
/// @param completion 结果回调
- (void)acceptRequest:(NSString *)userId completion:(nonnull RCLVResultBlock)completion;

/// 拒绝上麦请求
/// @param userId 目标用户id
/// @param completion 结果回调
- (void)rejectRequest:(NSString *)userId completion:(nonnull RCLVResultBlock)completion;

/// 获取当前申请上麦的所有用户
/// @param completion 结果回调
- (void)getRequests:(void(^)(RCLiveVideoErrorCode, NSArray<NSString *> *))completion;

/// 邀请用户上麦
/// @param userId 目标用户id
/// @param index 邀请位置
/// 注意：
/// 麦位总数由连麦类型决定，比如：一对一场景，麦位数量为1；九宫格，麦位数量为9。
/// 如果麦位传入-1，SDK 会自动查询第一个空麦位。
/// @param completion 结果回调
- (void)inviteLiveVideo:(NSString *)userId atIndex:(NSInteger)index completion:(nonnull RCLVResultBlock)completion;

/// 取消上麦邀请
/// @param userId 目标用户id
/// @param completion 结果回调
- (void)cancelInvitation:(NSString *)userId completion:(nonnull RCLVResultBlock)completion;

/// 接受上麦邀请，并上麦
/// 如果上麦的麦位已被占用，SDK 会自动查询第一个空麦位。
/// @param completion 结果回调
- (void)acceptInvitation:(nonnull RCLVResultBlock)completion;

/// 拒绝上麦邀请
/// @param completion 结果回调
- (void)rejectInvitation:(nonnull RCLVResultBlock)completion;

/// 获取当前邀请上麦的所有用户
/// @param completion 结果回调
- (void)getInvitations:(void(^)(RCLiveVideoErrorCode, NSArray<NSString *> *))completion;

/// 结束视频直播
/// @param completion 结果回调
/// @param userId 停止视频直播的用户
- (void)finishLiveVideo:(NSString *)userId completion:(nullable RCLVResultBlock)completion;

/// 更新房间自定义属性，建议属性数量<50
/// @param roomInfo 房间信息属性<key, value>
- (void)setRoomInfo:(NSDictionary<NSString *, NSString *> *)roomInfo completion:(nullable RCLVResultBlock)completion;

@end

@interface RCLiveVideoEngine (message)

/// 将用户踢出房间
/// @param userId 被踢出用户的id
/// @param completion 结果回调
- (void)kickOutRoom:(NSString *)userId completion:(nullable RCLVResultBlock)completion;

/// 发送直播房间消息
/// @param content 消息内容
/// @param completion 结果回调
- (void)sendMessage:(RCMessageContent *)content completion:(nullable RCLVResultBlock)completion;

@end

@interface RCLiveVideoEngine (view)

/// 直播视频页面
- (UIView *)previewView;

/// 设置视频合流布局类型
/// @param type 布局类型
- (void)setMixType:(RCLiveVideoMixType)type;


@end

NS_ASSUME_NONNULL_END
