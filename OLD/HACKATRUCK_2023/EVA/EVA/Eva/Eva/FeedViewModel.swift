import Foundation

class FeedViewModel : ObservableObject{
    
    @Published var feeds : [Feeds] = []
    
    func fetch(tema: String, portugues: Bool){
        
        let date = Date()
        
        let calendar = Calendar.current
        let components = calendar.dateComponents([.year, .day, .month], from: date)
        var year = components.year!
        var month = components.month!
        var day = components.day! - 1
        
        if(day < 1){
            day = 28
            month = month - 1
            if(month < 1){
                month = 12
                year = year - 1
            }
        }
        
        // adicionando zero na frente do dia/mes caso um desses seja um numero unico
        var day_zero = ""
        var month_zero = ""
        
        if(day < 10){
            day_zero = "0"
        }
        
        if(month < 10){
            month_zero = "0"
        }
            
        guard let url = URL(string: "https://newsapi.org/v2/everything?language=\(portugues ? "pt" : "en")&q=\(tema.replacingOccurrences(of: " ", with: "%20"))&searchIn=title&from=\(year)-\(month_zero)\(month)-\(day_zero)\(day)&sortBy=popularity&apiKey=bd51aa4fb45542de836cc0a02ff661f5") else{
            return
        }
        
        let task = URLSession.shared.dataTask(with: url){ [weak self] data, _, error in
            guard let data = data, error == nil else{
                return
            }
            
            do{
                let parsed = try JSONDecoder().decode(dt.self, from: data)
                
                DispatchQueue.main.async{
                    self?.feeds = parsed.articles.shuffled()
                }
                
            }catch{
                print(error)
            }
            
        }
        task.resume()
    }
    
}


