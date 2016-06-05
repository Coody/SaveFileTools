//
//  SaveFileToolsManager.h
//  PushMeBaby
//
//  Created by Coody on 2016/6/3.
//
//

#import <Foundation/Foundation.h>

@protocol SaveFileTools_Policy;

/**  */
extern NSString *const K_SAVE_FILE_PATH_PREFIX;
/**  */
extern NSString *const K_SAVE_FILE_FOLDER_NAME;


/**
 *  This manager is an easy way to manage your all kinds of custom SaveFileTools objects. 
    
    SaveFileTools is a save file class that you can use it to save file and you can inherit it and create your own SaveFileTools object.
 
    Example: If you create a game and you have three kinds of data like "player data", "Map data", "Albumn data" wanna to save. You can create three kinds of custom SaveFileTools and create your own Model class in your custom SaveFileTools and save it in Model property. SaveFileToolsManager can organize them and manage them easily.
    
    中文：
    SaveFileToolsManager 是一個方便讓您管理你的檔案的檔案管理員。
    SaveFileTools 是一個能儲存檔案的工具類別，你可以繼承他、並且建立自己的 Model ，並且存在此類別的 Model property 中。
    例：如果你有一個遊戲裡面有三種資料要存檔：玩家資料、地圖資料、相片資料，那麼你可以建立三個繼承 SaveFileTools 的類別，並且裡面自己建立自己要的 Model，並存入 Model property 中，最後透過管理者來處理整個存檔，每個存檔都會用 key 來當成總存檔的資料夾名稱（因此您可以輕易的建立多個存檔。）
 
 */
@interface SaveFileToolsManager : NSObject

/**  */
@property (nonnull , nonatomic , readonly) NSArray *saveFileToolsArray;

+(nonnull instancetype)sharedInstance;

/** 
 * 初始化設定路徑
 */
-(void)initialFilePath:(nullable NSString *)tempFilePath;

/**
 *  initial SaveFile system , add an array with custom SaveFileTools class name using NSString.
 *
 *  @param tempArray Your custom SaveFileTools name using NSString
 *  @param tempKey   Save File name( should not be the same ). It will create a folder to save all your custom SaveFileTools objects.
 */
-(void)initialSaveFileToolsWithClassNameArray:(nullable NSArray<NSString *> *)tempArray
                                      withKey:(nonnull NSString *)tempKey;

/** 
 *
 */
-(BOOL)saveWithKey:(nonnull NSString *)tempKey;

/** 
 *
 */
-(BOOL)loadWithKey:(nonnull NSString *)tempKey;

// TODO:
-(BOOL)saveWithKey:(nonnull NSString *)tempKey
withSaveFileToolsName:(NSString *)tempSaveFileToolsName;

// TODO:
-(BOOL)loadWithKey:(nonnull NSString *)tempKey
withSaveFileToolsName:(NSString *)tempSaveFileToolsName;

// TODO:
-(BOOL)saveWithKey:(nonnull NSString *)tempKey
withSaveFileToolsIndex:(NSUInteger)index;

// TODO:
-(BOOL)loadWithKey:(nonnull NSString *)tempKey
withSaveFileToolsIndex:(NSUInteger)index;

#pragm mark - Get SaveFileTools
// TODO:
-(SaveFileTools *)getSaveFileToolsWithName:(NSString *)tempSaveFileToolsName;

// TODO:
-(SaveFileTools *)getSaveFileToolsWithIndex:(NSUInteger)index;

@end
