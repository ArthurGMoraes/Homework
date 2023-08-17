
import Foundation
import SwiftUI

class ViewModel : ObservableObject{
    
    @Published var usuario : [Usuario] = []
    @Published var caixinha_state : Bool = false
    @Published var intervalo : String = ""
    @Published var nome : String = ""
    @Published var tema : String = ""
    @Published var portugues : Bool = false
    
    func fetch(){
        
        guard let url = URL(string: "http://192.168.128.249:1880/usuario") else{
            return
        }
        
        let task = URLSession.shared.dataTask(with: url){ [weak self] data, _, error in
            guard let data = data, error == nil else{
                return
            }
            
            do{
                let parsed = try JSONDecoder().decode([Usuario].self, from: data)
                
                DispatchQueue.main.async{
                    self?.usuario = parsed
                    
                    for  u in self!.usuario{
                        Tema.tema = u.tema
                        Tema.portugues = u.portugues
                        
                        self!.caixinha_state = u.caixinha_state!
                        self!.portugues = u.portugues!
                        self!.nome = u.nome!
                        self!.tema = u.tema!
                        self!.intervalo = u.intervalo!
                    }
                }
                
            }catch{
                print(error)
            }
            
        }
        task.resume()
    }
    
    func edit(id : String, rev : String, nome : String, tema : String, intervalo : String, caixinha_state : Bool, portugues : Bool){
        
        if(nome == "" || tema == "" || intervalo == ""){
            return
        }
        
        let body: [String: Any] = ["_id" : id, "_rev" : rev, "nome" : nome, "tema" : tema, "intervalo" : intervalo, "caixinha_state" : caixinha_state, "portugues" : portugues]
        
        let jsonData = try? JSONSerialization.data(withJSONObject: body)
                
        guard let url = URL(string: "http://192.168.128.249:1880/usuario") else{
            return
        }
        var request = URLRequest(url: url)
        
        request.httpMethod = "PUT"
        
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
