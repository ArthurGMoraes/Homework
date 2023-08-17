
import Foundation

class NoticiasViewModel : ObservableObject{
    
    @Published var noticias : [Noticias] = []
    
    func fetch(){
        
        guard let url = URL(string: "http://192.168.128.249:1880/noticias") else{
            return
        }
        
        let task = URLSession.shared.dataTask(with: url){ [weak self] data, _, error in
            guard let data = data, error == nil else{
                return
            }
            
            do{
                let parsed = try JSONDecoder().decode([Noticias].self, from: data)
                
                DispatchQueue.main.async{
                    self?.noticias = parsed
                }
                
            }catch{
                print(error)
            }
            
        }
        task.resume()
    }
    
    func post(titulo : String, data : String, descricao : String, url : String){
        
        let body: [String: Any] = ["titulo" : titulo, "data" : data, "descricao" : descricao, "url" : url]
        
        let jsonData = try? JSONSerialization.data(withJSONObject: body)
                
        guard let url = URL(string: "http://192.168.128.249:1880/noticias") else{
            return
        }
        var request = URLRequest(url: url)
        
        request.httpMethod = "POST"
        
        request.setValue("\(String(describing: jsonData?.count))", forHTTPHeaderField: "Content-Length")
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        
        request.httpBody = jsonData
        
        let task = URLSession.shared.dataTask(with: request) { data, response, error in
            guard let data = data, error == nil else {
                print(error?.localizedDescription ?? "No data")
                return
            }

            let responseJSON = try? JSONSerialization.jsonObject(with: data, options: [])
            if let responseJSON = responseJSON as? [String: Any] {
                print(responseJSON)
            }
        }

        task.resume()
    }
    
    func delete(id : String, rev : String){
        
        let body: [String: Any] = ["_id" : id, "_rev" : rev]
        
        let jsonData = try? JSONSerialization.data(withJSONObject: body)
                
        guard let url = URL(string: "http://192.168.128.249:1880/noticias") else{
            return
        }
        var request = URLRequest(url: url)
        
        request.httpMethod = "DELETE"
        
        request.setValue("\(String(describing: jsonData?.count))", forHTTPHeaderField: "Content-Length")
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        
        request.httpBody = jsonData
        
        let task = URLSession.shared.dataTask(with: request) { data, response, error in
            guard let data = data, error == nil else {
                print(error?.localizedDescription ?? "No data")
                return
            }

            let responseJSON = try? JSONSerialization.jsonObject(with: data, options: [])
            if let responseJSON = responseJSON as? [String: Any] {
                print(responseJSON)
            }
        }

        task.resume()
    }
    
}
