//
//  Configuracoes.swift
//  Eva
//
//  Created by Student05 on 13/06/23.
//

import SwiftUI

struct Configuracoes: View {
    
    @StateObject private var viewModel = ViewModel()
    
    @StateObject private var feedViewModel = FeedViewModel()
    
    @State private var edit_alert_state : Bool = false
    
    @State private var user_name : String = ""
    
    @State private var user_theme : String = ""
    
    @State private var box_interval : String = ""
    
    @State private var portugues : Bool = false
    
    @State private var box_state : Bool = false
    
    
    
    var body: some View {
        ZStack{
            
            Color(.white)
            
            LinearGradient(
                colors: [.white, Color("lightPurple")],
                startPoint: .top,
                endPoint: .bottom)
            
            VStack{
                
                HStack{
                    AsyncImage(url: URL(string: "https://cdn-icons-png.flaticon.com/512/143/143567.png")){
                        image in
                        image
                            .resizable()
                            .aspectRatio(contentMode: .fill)
                    } placeholder: {
                        Color("lightPurple")
                    }.frame(width: 30, height: 30)
                    
                    Text("Configurações").font(.title2)
                    Spacer()
                    
                }.padding([.top, .leading, .trailing], 20.0)
                
                Divider()
                
                
                ScrollView{
                    
                    ForEach(viewModel.usuario, id: \.self._id){ usuario in
                        
                        VStack(alignment: .leading){
                            
                            Text("Configurações do usuário").font(.title2).padding(.vertical, 10).foregroundColor(Color("Purple"))
                            
                            Text("Nome").multilineTextAlignment(.trailing)
                            
                            TextField(usuario.nome!, text: $user_name).textFieldStyle(.roundedBorder).padding(.top, 0).padding(.trailing, 50)
                            
                            Text("Tema")
                            
                            TextField(usuario.tema!, text: $user_theme).textFieldStyle(.roundedBorder).padding(.top, 0).padding(.trailing, 50)
                            
                            Text("Configurações da Eva").font(.title2).padding(.vertical, 10).foregroundColor(Color("Purple"))
                            
                            Text("Intervalo entre notícias (em segundos)")
                            
                            TextField(usuario.intervalo!, text: $box_interval).textFieldStyle(.roundedBorder).padding(.top, 0).padding(.trailing, 160)
                            
                            Toggle(isOn: $box_state) {
                                Text("Ligada/desligada")
                            }.padding(.trailing, 155).padding(.top, 5)
                            
                            Toggle(isOn: $portugues) {
                                Text("Português")
                            }.padding(.trailing, 155).padding(.top, 5).padding(.bottom, 10)
                            
                        }.padding(.leading, 10)
                        
                        Button("Alterar"){
                            
                            edit_alert_state = true
                            
                            viewModel.edit(id: usuario._id!, rev: usuario._rev!, nome: user_name, tema: user_theme, intervalo: box_interval, caixinha_state: box_state, portugues: portugues)
                            
                            UIApplication.shared.sendAction(#selector(UIResponder.resignFirstResponder), to: nil, from: nil, for: nil)
                            
                            
                        }.padding()
                        .background(Color("Purple"))
                        .foregroundColor(Color.white)
                        .clipShape(Capsule())
                        .alert((user_name == "" || user_theme == "" || box_interval == "") ? "Preencha todos os campos." : "Alterações salvas.", isPresented: $edit_alert_state){
                            
                            Button("OK", role: .cancel) {
                                viewModel.fetch()
                                feedViewModel.fetch(tema: Tema.tema!, portugues: Tema.portugues!)
                            }
                        }
                        
                    }
                    
                    Spacer()
                    
                }
                
            }.padding(10).onAppear(){
                viewModel.fetch()
                
                DispatchQueue.main.asyncAfter(deadline: .now() + 3){
                    portugues = viewModel.portugues
                    box_state = viewModel.caixinha_state
                    box_interval = viewModel.intervalo
                    user_name = viewModel.nome
                    user_theme = viewModel.tema
                }
            }
        }
        
        
    }
}

struct Configuracoes_Previews: PreviewProvider {
    static var previews: some View {
        Configuracoes()
    }
}
