import Foundation

struct Feeds : Decodable{
    var title : String?
    var description : String?
    var url : String?
    var publishedAt : String?
}

struct dt : Decodable{
    var articles : [Feeds]
}

struct Tema {
    static var tema : String?
    static var portugues : Bool?
}
