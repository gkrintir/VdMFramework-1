void xsecsPerBCID_PCC()
{
//=========Macro generated from canvas: can/
//=========  (Fri Dec 15 00:54:37 2017) by ROOT version5.99/05
   TCanvas *can = new TCanvas("can", "",1,1,800,576);
   can->SetHighLightColor(2);
   can->Range(-283.15,7.414201,2548.35,7.566883);
   can->SetFillColor(0);
   can->SetBorderMode(0);
   can->SetBorderSize(2);
   can->SetFrameBorderMode(0);
   can->SetFrameBorderMode(0);
   
   Double_t _fx1006[5] = {
   872,
   41,
   1783,
   2063,
   281};
   Double_t _fy1006[5] = {
   7.49969,
   7.462775,
   7.470801,
   7.467366,
   7.518054};
   Double_t _fex1006[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fey1006[5] = {
   0.0239618,
   0.02312657,
   0.02456162,
   0.02364579,
   0.02338205};
   TGraphErrors *gre = new TGraphErrors(5,_fx1006,_fy1006,_fex1006,_fey1006);
   gre->SetName("");
   gre->SetTitle(";BCID;#sigma_{Vis} (Barn)");
   gre->SetFillColor(1);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#00cc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","",100,0,2265.2);
   Graph_Graph1006->SetMinimum(7.42947);
   Graph_Graph1006->SetMaximum(7.551614);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1006->SetLineColor(ci);
   Graph_Graph1006->GetXaxis()->SetTitle("BCID");
   Graph_Graph1006->GetXaxis()->SetNdivisions(11);
   Graph_Graph1006->GetXaxis()->SetLabelFont(42);
   Graph_Graph1006->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetXaxis()->SetTitleFont(42);
   Graph_Graph1006->GetYaxis()->SetTitle("#sigma_{Vis} (Barn)");
   Graph_Graph1006->GetYaxis()->SetLabelFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetYaxis()->SetTitleFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1006);
   
   gre->Draw("ap");
   TLatex *   tex = new TLatex(0.93,0.88,"2017  (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.88,"CMS #bf{#scale[0.75]{#it{Preliminary}}}");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
   can->Modified();
   can->cd();
   can->SetSelected(can);
}
