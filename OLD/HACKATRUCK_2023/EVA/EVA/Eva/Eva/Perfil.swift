//
//  Perfil.swift
//  Eva
//
//  Created by Student05 on 01/06/23.
//

import SwiftUI

struct Perfil: View {
    
    @StateObject private var viewModel = ViewModel()
    
    @StateObject private var noticiasViewModel = NoticiasViewModel()
    
    @State private var delete_alert_state : Bool = false

    
    var body: some View {
        ZStack{
            
            Color(.white)
            
            LinearGradient(
                colors: [.white, Color("lightPurple")],
                startPoint: .top,
                endPoint: .bottom)
            
            VStack{
                
                ForEach(viewModel.usuario, id: \.self._id){ usuario in
                    
                    HStack{
                        AsyncImage(url: URL(string: "https://cdn-icons-png.flaticon.com/512/143/143567.png")){
                            image in
                            image
                                .resizable()
                                .aspectRatio(contentMode: .fill)
                        } placeholder: {
                            Color("lightPurple")
                        }.frame(width: 30, height: 30)
                        
                        Text("Bem vindo, \(usuario.nome!)").font(.title2)
                        Spacer()
    
                    }.padding([.top, .leading, .trailing], 20.0)
                    
                    Divider()
                }
                
                ScrollView{
                    
                    ForEach(viewModel.usuario, id: \.self._id){ usuario in
                        
                        Text("'\(usuario.tema!)'").font(.system(size: 35)).multilineTextAlignment(.center)
                            .foregroundColor(Color("Purple")).fontWeight(.bold).padding(.top, 10)
                        Text("é seu tema atual").foregroundColor(Color("Purple")).padding(.bottom, 25)
                    }
                    
                    HStack{
                        Image(systemName: "heart")
                        Text("Suas notícias favoritas").multilineTextAlignment(.trailing).font(.caption)
                        
                        
                    }.padding(.top, -3)
                    
                    ForEach(noticiasViewModel.noticias, id: \.self._id){ noticia in
                        
                        VStack(alignment: .leading){
                            
                            HStack(alignment: .top){
                                
                                Text(noticia.titulo!).font(.subheadline).fontWeight(.bold).padding(4)
                                
                                Spacer()
                                
                                Button{
                                    noticiasViewModel.delete(id: noticia._id!, rev: noticia._rev!)
                                    delete_alert_state = true
                                } label :{
                                    Image(systemName: "xmark")
                                }.alert("Notícia excluída.", isPresented: $delete_alert_state) {
                                    Button("OK", role: .cancel) {
                                        noticiasViewModel.fetch()
                                    }
                                }
                                
                            }
                            
                            Text(noticia.descricao!).font(.caption).padding(4)
                            
                            HStack{
                                Text(noticia.data!.prefix(10)).font(.caption).foregroundColor(Color("Purple")).fontWeight(.bold)
                                
                                Spacer()
                                
                                Link("Visitar", destination: URL(string: "\(noticia.url!)")!)
                            }
                            
                        }.padding(20).background(Color.white)
                                .cornerRadius(20)
                                .shadow(color: Color.black.opacity(0.2), radius: 5, x: 0, y: 2)

                    }
                    
                    Spacer()
                }
                
            }.padding(10).onAppear(){
                viewModel.fetch()
                noticiasViewModel.fetch()
            }
        }
        
        
    }
}

struct Perfil_Previews: PreviewProvider {
    static var previews: some View {
        Perfil()
    }
}
